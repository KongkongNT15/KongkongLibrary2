#ifndef KLIB_KONGKONG_TEXT_STRINGHELPER_H
#define KLIB_KONGKONG_TEXT_STRINGHELPER_H

#include "base.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 文字列処理
    /// </summary>
    class StringHelper final {
    private:

    public:

        KLIB_STATIC_CLASS(StringHelper);

        /// <summary>
        /// 文字列の長さを取得
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="p">文字列へのポインター</param>
        /// <returns>文字列の長さ</returns>
        template <CChar TChar>
        static constexpr ssize_t GetLengthUnsafe(const TChar* p) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool IsEqualsUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool IsEqualsUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool IsEqualsUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 2つの文字列が一致しているかを確認
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="lengthLeft">1つめの文字列の長さ</param>
        /// <param name="left">1つめの文字列</param>
        /// <param name="lengthRight">2つめの文字列の長さ</param>
        /// <param name="right">2つめの文字列</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        KLIB_NODISCARD static constexpr bool IsEqualsUnsafe(
            ssize_t lengthLeft,
            const TChar* left,
            ssize_t lengthRight,
            const TChar* right
        ) noexcept;
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr ssize_t StringHelper::GetLengthUnsafe(const TChar* p) noexcept
    {
        const TChar* p1 = p;

        while (true) {
            if (!*p1) return p1 - p;
            ++p1;
        }
    }

    template <CChar TChar>
    constexpr bool StringHelper::IsEqualsUnsafe(
        ssize_t lengthLeft,
        const TChar* left,
        ssize_t lengthRight,
        const TChar* right
    ) noexcept
    {
        if (lengthLeft != lengthRight) return false;

        const TChar* end = left + lengthLeft;
        const TChar* pLeft = left;
        const TChar* pRight = right;

        while (pLeft != end) {
            if (*pLeft != *pRight) return false;

            ++pLeft;
            ++pRight;
        }

        return true;
    }
}

#endif //!KLIB_KONGKONG_TEXT_STRINGHELPER_H