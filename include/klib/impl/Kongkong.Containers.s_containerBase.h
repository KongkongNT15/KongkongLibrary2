#ifndef KLIB_KONGKONG_CONTAINTERS_CONTAINERBASE_H
#define KLIB_KONGKONG_CONTAINTERS_CONTAINERBASE_H

#include "base.h"
#include "Kongkong.Containers.ContainerHelper.h"

namespace klib::Kongkong::Containers
{
    struct s_containerBase {
    protected:
        /// <summary>
        /// 要素数
        /// </summary>
        ssize_t m_length;

        explicit constexpr s_containerBase() noexcept;

        explicit constexpr s_containerBase(
            ssize_t length
        ) noexcept;
    public:

        /// <summary>
        /// IndexOf()で見つからなかったときの戻り値
        /// </summary>
        /// <returns></returns>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;

        /// <summary>
        /// コンテナが空かを判定
        /// </summary>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool IsEmpty() const noexcept;

        /// <summary>
        /// 要素数を取得
        /// </summary>
        [[nodiscard]] constexpr ssize_t Length() const noexcept;
    };
}

namespace klib::Kongkong::Containers
{
    constexpr s_containerBase::s_containerBase() noexcept
        : m_length(0)
    {
    }

    constexpr s_containerBase::s_containerBase(
        ssize_t length
    ) noexcept
        : m_length(length)
    {
    }

    consteval ssize_t s_containerBase::NotFound() noexcept
    {
        return ContainerHelper::NotFound();
    }

    constexpr bool s_containerBase::IsEmpty() const noexcept
    {
        return m_length == 0;
    }

    constexpr ssize_t s_containerBase::Length() const noexcept
    {
        return m_length;
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_CONTAINERBASE_H