#ifndef KLIB_KONGKONG_THREADING_ASYNC_AWAITER_H
#define KLIB_KONGKONG_THREADING_ASYNC_AWAITER_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Threading.Async.TaskStatus.h"

#include <coroutine>
#include <atomic>

namespace klib::Kongkong::Threading::Async
{
    class Awaiter : public ValueType {
    private:
    protected:
        ::std::coroutine_handle<> m_other;
        ::std::atomic<TaskStatus> m_status;

        constexpr Awaiter() noexcept;

        Awaiter(Awaiter const&) = default;
        Awaiter(Awaiter&&) = default;

        Awaiter& operator=(Awaiter const&) = default;
        Awaiter& operator=(Awaiter&&) = default;
        
    public:

        struct promise_type_base {
            Awaiter* m_pAwaiter;

            constexpr promise_type_base() noexcept;

            ::std::suspend_never final_suspend() const noexcept;
            constexpr ::std::suspend_never initial_suspend() const noexcept;
            constexpr void unhandled_exception() noexcept;
        };

        consteval bool await_ready() const noexcept;

        void await_suspend(
            std::coroutine_handle<> h
        );
        
        [[nodiscard]] TaskStatus Status() const noexcept;

        void Wait() const noexcept;
    };
}

namespace klib::Kongkong::Threading::Async
{
    constexpr Awaiter::Awaiter() noexcept
        : m_other(nullptr)
        , m_status(TaskStatus::Running)
    {
    }

    constexpr Awaiter::promise_type_base::promise_type_base() noexcept
        : m_pAwaiter(nullptr)
    {
    }

    constexpr ::std::suspend_never
    Awaiter::promise_type_base::initial_suspend() const noexcept
    {
        return {};
    }

    constexpr void Awaiter::promise_type_base::unhandled_exception() noexcept
    {
        if (m_pAwaiter != nullptr)
        {
            m_pAwaiter->m_status = TaskStatus::Faulted;
        }
    }

    consteval bool Awaiter::await_ready() const noexcept
    {
        return false;
    }

    inline TaskStatus Awaiter::Status() const noexcept
    {
        return m_status.load();
    }
}

#endif //!KLIB_KONGKONG_THREADING_ASYNC_AWAITER_H