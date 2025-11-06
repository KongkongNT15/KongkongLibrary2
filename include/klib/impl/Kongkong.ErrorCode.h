#ifndef KLIB_KONGKONG_ERRORCODE_H
#define KLIB_KONGKONG_ERRORCODE_H

#include "base.h"

namespace klib::Kongkong
{
    /// <summary>
    /// エラーコード
    /// </summary>
    struct ErrorCode {
    private:
        enum s_code : uint32_t {
            NoError,
            AlreadyInitialized,
        };
        uint32_t m_value;

        constexpr ErrorCode(
            s_code value
        ) noexcept;
    public:

        [[nodiscard]] static constexpr ErrorCode NoError() noexcept;

        [[nodiscard]] static constexpr ErrorCode AlreadyInitialized() noexcept;

        constexpr ErrorCode() noexcept;

        [[nodiscard]] constexpr uint32_t Value() const noexcept;

        void Throw() const;

        [[nodiscard]] String ToString() const;
    };
}

namespace klib::Kongkong
{
    constexpr ErrorCode::ErrorCode(
        s_code value
    ) noexcept
        : m_value(static_cast<uint32_t>(value))
    {
    }

    constexpr ErrorCode ErrorCode::NoError() noexcept
    {
        return s_code::NoError;
    }

    constexpr ErrorCode ErrorCode::AlreadyInitialized() noexcept
    {
        return s_code::AlreadyInitialized;
    }

    constexpr ErrorCode::ErrorCode(
    ) noexcept
        : ErrorCode(NoError())
    {
    }
}

#endif //!KLIB_KONGKONG_ERRORCODE_H