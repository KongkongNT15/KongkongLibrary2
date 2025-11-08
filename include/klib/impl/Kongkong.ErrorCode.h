#ifndef KLIB_KONGKONG_ERRORCODE_H
#define KLIB_KONGKONG_ERRORCODE_H

#include "base.h"
#include "Kongkong.ValueType.h"

namespace klib::Kongkong
{
    /// <summary>
    /// エラーコード
    /// </summary>
    struct ErrorCode final : public ValueType {
    private:
        enum s_code : uint32_t {
            NoError,
            AlreadyClosed,
            AlreadyInitialized,
            ArgumentNonPositive
        };
        uint32_t m_value;

        constexpr ErrorCode(
            s_code value
        ) noexcept;
    public:

        [[nodiscard]] static constexpr ErrorCode NoError() noexcept;

        [[nodiscard]] static constexpr ErrorCode AlreadyClosed() noexcept;
        [[nodiscard]] static constexpr ErrorCode AlreadyInitialized() noexcept;
        [[nodiscard]] static constexpr ErrorCode ArgumentNonPositive() noexcept;

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

    constexpr ErrorCode ErrorCode::AlreadyClosed() noexcept
    {
        return s_code::AlreadyClosed;
    }

    constexpr ErrorCode ErrorCode::AlreadyInitialized() noexcept
    {
        return s_code::AlreadyInitialized;
    }

    constexpr ErrorCode ErrorCode::ArgumentNonPositive() noexcept
    {
        return s_code::ArgumentNonPositive;
    }

    constexpr ErrorCode::ErrorCode(
    ) noexcept
        : ErrorCode(NoError())
    {
    }
}

#endif //!KLIB_KONGKONG_ERRORCODE_H