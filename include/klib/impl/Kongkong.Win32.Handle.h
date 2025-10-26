#ifndef KONGKONG_WIN32_HANDLE_H
#define KONGKONG_WIN32_HANDLE_H

#include "base.h"
#include "Kongkong.HandleType.h"

#if KLIB_ENV_WINDOWS

namespace klib::Kongkong::Win32
{
    /// <summary>
    /// Win32ハンドル
    /// </summary>
    class Handle : public HandleType {
        friend bool operator==(
            Handle const& left,
            ::std::nullptr_t
        ) noexcept;
    private:
        struct s_handle {
            /// <summary>
            /// 無効な値を取得
            /// </summary>
            [[nodiscard]] static ::HANDLE InvalidValue() noexcept;

            /// <summary>
            /// Win32の生ハンドル
            /// </summary>
            ::HANDLE m_handle;

            ~s_handle();

            /// <summary>
            /// ハンドルを閉じる
            /// </summary>
            /// <returns>操作に成功したかどうか</returns>
            bool Close() noexcept;
        };

        /// <summary>
        /// ハンドルインスタンス
        /// メンバーにすることで派生クラスを作ってもoperator=()がオーバーロードされないようにする
        /// </summary>
        s_handle m_handle;
        
    public:

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [[nodiscard]] bool operator!() const noexcept;

        /// <summary>
        /// 
        /// </summary>
        [[nodiscard]] operator bool() const noexcept;

        /// <summary>
        /// Win32の生ハンドルを取得
        /// </summary>
        [[nodiscard]] constexpr ::HANDLE RawHandle() const noexcept;
    };

    /// <summary>
    /// 
    /// </summary>
    /// <param name="left"></param>
    /// <returns></returns>
    [[nodiscard]] bool operator==(
        Handle const& left,
        ::std::nullptr_t
    ) noexcept;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="right"></param>
    /// <returns></returns>
    [[nodiscard]] bool operator==(
        ::std::nullptr_t,
        Handle const& right
    ) noexcept;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="left"></param>
    /// <returns></returns>
    [[nodiscard]] bool operator!=(
        Handle const& left,
        ::std::nullptr_t
        ) noexcept;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="right"></param>
    /// <returns></returns>
    [[nodiscard]] bool operator!=(
        ::std::nullptr_t,
        Handle const& right
        ) noexcept;
}

namespace klib::Kongkong::Win32
{
    inline ::HANDLE Handle::s_handle::InvalidValue() noexcept
    {
        return INVALID_HANDLE_VALUE;
    }

    inline Handle::s_handle::~s_handle()
    {
        if (m_handle == InvalidValue()) return;

        ::CloseHandle(m_handle);
    }

    inline bool Handle::s_handle::Close() noexcept
    {
        bool result = static_cast<bool>(::CloseHandle(m_handle));
        m_handle = InvalidValue();
    }

    inline bool Handle::operator!() const noexcept
    {
        return m_handle.m_handle == Handle::s_handle::InvalidValue();
    }

    inline Handle::operator bool() const noexcept
    {
        return m_handle.m_handle != Handle::s_handle::InvalidValue();
    }

    constexpr ::HANDLE Handle::RawHandle() const noexcept
    {
        return m_handle.m_handle;
    }

    inline bool operator==(
        Handle const& left,
        ::std::nullptr_t
    ) noexcept
    {
        return left.RawHandle() == Handle::s_handle::InvalidValue();
    }

    inline bool operator==(
        ::std::nullptr_t,
        Handle const& right
    ) noexcept
    {
        return right == nullptr;
    }

    inline bool operator!=(
        Handle const& left,
        ::std::nullptr_t
        ) noexcept
    {
        return !(left == nullptr);
    }

    inline bool operator!=(
        ::std::nullptr_t,
        Handle const& right
        ) noexcept
    {
        return !(right == nullptr);
    }
}

#endif //KLIB_ENV_WINDOWS

#endif //!KONGKONG_WIN32_HANDLE_H