#ifndef KLIB_KONGKONG_NUMERICS_MATH_H
#define KLIB_KONGKONG_NUMERICS_MATH_H

#include "base.h"

#include <math.h>
#include <numbers>

namespace klib::Kongkong::Numerics
{
    /// <summary>
    /// 数学関数
    /// </summary>
    class Math final {
    private:

    public:

        KLIB_STATIC_CLASS(Math);

        /// <summary>
        /// 数値を絶対値化
        /// </summary>
        /// <typeparam name="TNum">符号付き数値型</typeparam>
        /// <param name="value">値</param>
        /// <returns>絶対値化した値</returns>
        template <CSignedNumber TNum>
        KLIB_NODISCARD static KLIB_CPP23_CONSTEXPR TNum Abs(TNum value) noexcept;

        /// <summary>
        /// (x * y) + zを計算
        /// </summary>
        /// <param name="x">数値</param>
        /// <param name="y">数値</param>
        /// <param name="z">数値</param>
        /// <returns>計算結果</returns>
        KLIB_NODISCARD static KLIB_CPP23_CONSTEXPR double FusedMultiplyAdd(double x, double y, double z) noexcept;

        /// <summary>
        /// 円周率
        /// </summary>
        /// <typeparam name="TNum">数値型</typeparam>
        template <CNumber TNum = double>
        KLIB_NODISCARD static constexpr TNum PI() noexcept;
    };
}

namespace klib::Kongkong::Numerics
{
    template <CSignedNumber TNum>
    KLIB_CPP23_CONSTEXPR TNum Math::Abs(TNum value) noexcept
    {
#if KLIB_HAS_CPP23
        if consteval return value >= 0 ? value : -value;
        else {
#endif
        if constexpr (CFloat<TNum>) return ::fabs(value);
        // 符号付き整数値
        else if constexpr (sizeof(TNum) < sizeof(int)) return ::abs(static_cast<int>(value));
        else return ::abs(value);

#if KLIB_HAS_CPP23
        }
#endif
    }

    KLIB_CPP23_CONSTEXPR_OR_INLINE double Math::FusedMultiplyAdd(double x, double y, double z) noexcept
    {
#if KLIB_HAS_CPP23
        if consteval return (x * y) + z;
        else
#endif
        return ::fma(x, y, z);
    }

    template <CNumber TNum>
    constexpr TNum Math::PI() noexcept
    {
        if constexpr (CFloat<TNum>) return ::std::numbers::pi_v<TNum>;
        else return static_cast<TNum>(::std::numbers::pi);
    }
}

int main()
{
    
}

#endif //!KLIB_KONGKONG_NUMERICS_MATH_H