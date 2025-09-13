#ifndef KLIB_KONGKONG_NUMERICS_NUMBER_H
#define KLIB_KONGKONG_NUMERICS_NUMBER_H

#include "base.h"
#include "Kongkong.Numerics.NumberParseResult.h"

#include <limits.h>
#include <limits>

namespace klib::Kongkong::Numerics
{
    template <class T>
    struct Number {
    public:
        using NumberType = typename ::std::remove_const_t<T>;

        [[nodiscard]] static consteval bool IsSigned() noexcept;

        [[nodiscard]] static consteval NumberType MaxValue() noexcept;
        [[nodiscard]] static consteval NumberType MinValue() noexcept;

        [[nodiscard]] static NumberType Parse();

        [[nodiscard]] static consteval ssize_t Size() noexcept;

        [[nodiscard]] static NumberParseResult<NumberType> TryParse() noexcept;

        
    };

    template <>
    [[nodiscard]] consteval bool Number<long>::IsSigned() noexcept;

    template <>
    [[nodiscard]] consteval long Number<long>::MaxValue() noexcept;

    template <>
    [[nodiscard]] consteval long Number<long>::MinValue() noexcept;

    template <>
    struct Number<void> final {
        KLIB_STATIC_CLASS(Number);


    };

    struct {
        int Value;
        bool IsSuccess;
    };
}

namespace klib::Kongkong::Numerics
{
    template <class T>
    consteval ssize_t Number<T>::Size() noexcept
    {
        return sizeof(NumberType);
    }

    consteval bool Number<long>::IsSigned() noexcept
    {
        return true;
    }

    consteval long Number<long>::MaxValue() noexcept
    {
        return LONG_MAX;
    }

    consteval long Number<long>::MinValue() noexcept
    {
        return LONG_MIN;
    }
}

#endif //!KLIB_KONGKONG_NUMERICS_NUMBER_H