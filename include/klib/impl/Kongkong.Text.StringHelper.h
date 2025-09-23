#ifndef KLIB_KONGKONG_TEXT_STRINGHELPER_H
#define KLIB_KONGKONG_TEXT_STRINGHELPER_H

#include "base.h"
#include "Kongkong.Containers.ContainerHelper.h"

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
        /// IndexOf()で要素が見つからなかったときの戻り値
        /// </summary>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool CompareUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool CompareUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool CompareUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 文字列の順番を判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="lengthLeft">1つめの文字列の長さ</param>
        /// <param name="left">1つめの文字列</param>
        /// <param name="lengthRight">2つめの文字列の長さ</param>
        /// <param name="right">2つめの文字列</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr ::std::strong_ordering CompareUnsafe(
            ssize_t lengthLeft,
            const TChar* left,
            ssize_t lengthRight,
            const TChar* right
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool ContainsUnsafe(
            ssize_t,
            ::std::nullptr_t,
            TChar
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool ContainsUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool ContainsUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool ContainsUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// 文字列に指定の文字が含まれるかを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="c">文字</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool ContainsUnsafe(
            ssize_t length,
            const TChar* p,
            TChar c
        ) noexcept;

        /// <summary>
        /// 文字列に指定の部分文字列が含まれるかを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="lengthSub">部分文字列の長さ</param>
        /// <param name="sub">部分文字列へのポインター</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool ContainsUnsafe(
            ssize_t length,
            const TChar* p,
            ssize_t lengthSub,
            const TChar* sub
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static GenericStringMemory<TChar> Dump(
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static GenericStringMemory<TChar> Dump(
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        template <CChar TChar>
        [[nodiscard]] static GenericStringMemory<TChar> Dump(const TChar* str);

        template <CChar TChar>
        [[nodiscard]] static GenericStringMemory<TChar> Dump(ssize_t, const TChar* str);

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static GenericStringMemory<TChar> DumpUnsafe(
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static GenericStringMemory<TChar> DumpUnsafe(
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="TChar"></typeparam>
        /// <param name="str"></param>
        /// <returns></returns>
        template <CChar TChar>
        [[nodiscard]] static GenericStringMemory<TChar> DumpUnsafe(
            const TChar* str
        );

        /// <summary>
        /// 
        /// </summary>
        /// <typeparam name="TChar"></typeparam>
        /// <param name="length"></param>
        /// <param name="str"></param>
        /// <returns></returns>
        template <CChar TChar>
        [[nodiscard]] static GenericStringMemory<TChar> DumpUnsafe(
            ssize_t length,
            const TChar* str
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool EndsWithUnsafe(
            ssize_t,
            ::std::nullptr_t,
            TChar
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool EndsWithUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool EndsWithUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool EndsWithUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// 文字列が指定した文字で終了するかを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="c">文字</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool EndsWithUnsafe(
            ssize_t length,
            const TChar* p,
            TChar c
        ) noexcept;

        /// <summary>
        /// 文字列が指定した部分文字列で終了するかを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="lengthSub">部分文字列の長さ</param>
        /// <param name="sub">部分文字列へのポインター</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool EndsWithUnsafe(
            ssize_t length,
            const TChar* p,
            ssize_t lengthSub,
            const TChar* sub
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        ssize_t GetLengthUnsafe(
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 文字列の長さを取得
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="p">文字列へのポインター</param>
        /// <returns>文字列の長さ</returns>
        template <CChar TChar>
        static [[nodiscard]] constexpr ssize_t GetLengthUnsafe(
            const TChar* p
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool GreaterThanUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool GreaterThanUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool GreaterThanUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 辞書順でleftがrightより後かを確認
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="lengthLeft">1つめの文字列の長さ</param>
        /// <param name="left">1つめの文字列</param>
        /// <param name="lengthRight">2つめの文字列の長さ</param>
        /// <param name="right">2つめの文字列</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool GreaterThanUnsafe(
            ssize_t lengthLeft,
            const TChar* left,
            ssize_t lengthRight,
            const TChar* right
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr ssize_t IndexOfUnsafe(
            ssize_t,
            ::std::nullptr_t,
            TChar
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr ssize_t IndexOfUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr ssize_t IndexOfUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr ssize_t IndexOfUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// 文字列中の指定の文字の要素番号を取得
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="c">文字</param>
        /// <returns>指定した文字がある要素番号 見つからない場合はNotFound()</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr ssize_t IndexOfUnsafe(
            ssize_t length,
            const TChar* p,
            TChar c
        ) noexcept;

        /// <summary>
        /// 文字列中の指定の部分文字列の要素番号を取得
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="lengthSub">部分文字列の長さ</param>
        /// <param name="sub">部分文字列へのポインター</param>
        /// <returns>指定した部分文字列がある要素番号 見つからない場合はNotFound()</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr ssize_t IndexOfUnsafe(
            ssize_t length,
            const TChar* p,
            ssize_t lengthSub,
            const TChar* sub
        ) noexcept;

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
        [[nodiscard]] static constexpr bool IsEqualsUnsafe(
            ssize_t lengthLeft,
            const TChar* left,
            ssize_t lengthRight,
            const TChar* right
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool LessThanUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool LessThanUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool LessThanUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 辞書順でleftがrightより手前かを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="lengthLeft">1つめの文字列の長さ</param>
        /// <param name="left">1つめの文字列</param>
        /// <param name="lengthRight">2つめの文字列の長さ</param>
        /// <param name="right">2つめの文字列</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool LessThanUnsafe(
            ssize_t lengthLeft,
            const TChar* left,
            ssize_t lengthRight,
            const TChar* right
        ) noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static bool StartsWithUnsafe(
            ::std::nullptr_t,
            TChar
        ) = delete;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool StartsWithUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            const TChar*
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool StartsWithUnsafe(
            ssize_t,
            const TChar*,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        template <CChar TChar>
        static constexpr bool StartsWithUnsafe(
            ssize_t,
            ::std::nullptr_t,
            ssize_t,
            ::std::nullptr_t
        );

        /// <summary>
        /// 文字列が指定した文字で始まるかを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="c">文字</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool StartsWithUnsafe(
            const TChar* p,
            TChar c
        ) noexcept;

        /// <summary>
        /// 文字列が指定した部分文字列で始まるかを判定
        /// </summary>
        /// <typeparam name="TChar">文字型</typeparam>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="lengthSub">部分文字列の長さ</param>
        /// <param name="sub">部分文字列へのポインター</param>
        /// <returns>判定結果</returns>
        template <CChar TChar>
        [[nodiscard]] static constexpr bool StartsWithUnsafe(
            ssize_t length,
            const TChar* p,
            ssize_t lengthSub,
            const TChar* sub
        ) noexcept;
    };
}

namespace klib::Kongkong::Text
{
    consteval ssize_t StringHelper::NotFound() noexcept
    {
        return Containers::ContainerHelper::NotFound();
    }

    template <CChar TChar>
    constexpr ::std::strong_ordering StringHelper::CompareUnsafe(
        ssize_t lengthLeft,
        const TChar* left,
        ssize_t lengthRight,
        const TChar* right
    ) noexcept
    {
        ssize_t length = lengthLeft < lengthRight ? lengthLeft : lengthRight;

        const TChar* end = left + length;
        const TChar* pLeft = left;
        const TChar* pRight = right;

        while (pLeft != end) {
            if (*pLeft < *pRight) return ::std::strong_ordering::less;
            if (*pLeft > *pRight) return ::std::strong_ordering::greater;

            ++pLeft;
            ++pRight;
        }

        return true;
    }

    template <CChar TChar>
    constexpr bool StringHelper::ContainsUnsafe(
        ssize_t length,
        const TChar* p,
        TChar c
    ) noexcept
    {
        const TChar* end = p + length;
        while (p != end) {
            if (*p == c) return true;
            ++p;
        }

        return false;
    }

    template <CChar TChar>
    constexpr bool StringHelper::ContainsUnsafe(
        ssize_t length,
        const TChar* p,
        ssize_t lengthSub,
        const TChar* sub
    ) noexcept
    {
        if (lengthSub > length) return false;

        // ここで
        // lengthSub <= length

        const TChar* itr = p;
        const TChar* itrSub = sub;
        const TChar* end = p + lengthSub;

        while (itr != end) {
            
            if (*itr != *itrSub) break;

            ++itr;
            ++itrSub;
        }

        if (itr == end) return true;

        return ContainsUnsafe(
            length - 1,
            p + 1,
            lengthSub,
            sub
        );
    }

    template <CChar TChar>
    constexpr bool StringHelper::EndsWithUnsafe(
        ssize_t length,
        const TChar* p,
        TChar c
    ) noexcept
    {
        return (p[length - 1] == c && c != static_cast<TChar>('\0'));
    }

    template <CChar TChar>
    constexpr bool StringHelper::EndsWithUnsafe(
        ssize_t length,
        const TChar* p,
        ssize_t lengthSub,
        const TChar* sub
    ) noexcept
    {
        if (lengthSub > length) return false;

        // ここで
        // lengthSub <= length

        const TChar* ritr = p + length - 1;
        const TChar* rend = ritr - lengthSub;
        const TChar* ritrSub = sub + lengthSub - 1;

        while (ritr != rend) {
            if (*ritr != *ritrSub) return false;
            --ritr;
            --ritrSub;
        }

        return true;
    }

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
    constexpr bool StringHelper::GreaterThanUnsafe(
        ssize_t lengthLeft,
        const TChar* left,
        ssize_t lengthRight,
        const TChar* right
    ) noexcept
    {
        ssize_t length = lengthLeft < lengthRight ? lengthLeft : lengthRight;

        const TChar* end = left + length;
        const TChar* pLeft = left;
        const TChar* pRight = right;

        while (pLeft != end) {
            if (*pLeft < *pRight) return false;
            if (*pLeft > *pRight) return true;

            ++pLeft;
            ++pRight;
        }

        return false;
    }

    template <CChar TChar>
    constexpr ssize_t StringHelper::IndexOfUnsafe(
        ssize_t length,
        const TChar* p,
        TChar c
    ) noexcept
    {
        const TChar* itr = p;
        const TChar* end = p + length;

        while (itr != end) {
            if (*itr == c) return itr - p;
            ++itr;
        }

        return NotFound();
    }

    template <CChar TChar>
    constexpr ssize_t StringHelper::IndexOfUnsafe(
        ssize_t length,
        const TChar* p,
        ssize_t lengthSub,
        const TChar* sub
    ) noexcept
    {
        if (lengthSub > length) return NotFound();

        // ここで
        // lengthSub <= length

        const TChar* itr = p;
        const TChar* end = p + lengthSub;

        while (length >= lengthSub) {
            const TChar* itr2 = itr;
            const TChar* itrSub = sub;

            while (itr2 != end) {
                if (*itr2 != *itrSub) break;

                ++itr2;
                ++itrSub;
            }

            if (itr2 == end) return itr - p;

            --length;
            ++itr;
        }

        return NotFound();
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

    template <CChar TChar>
    constexpr bool StringHelper::LessThanUnsafe(
        ssize_t lengthLeft,
        const TChar* left,
        ssize_t lengthRight,
        const TChar* right
    ) noexcept
    {
        ssize_t length = lengthLeft < lengthRight ? lengthLeft : lengthRight;

        const TChar* end = left + length;
        const TChar* pLeft = left;
        const TChar* pRight = right;

        while (pLeft != end) {
            if (*pLeft > *pRight) return false;
            if (*pLeft < *pRight) return true;

            ++pLeft;
            ++pRight;
        }

        return false;
    }

    template <CChar TChar>
    constexpr bool StringHelper::StartsWithUnsafe(
        const TChar* p,
        TChar c
    ) noexcept
    {
        return (*p == c && c != static_cast<TChar>('\0'));
    }

    template <CChar TChar>
    constexpr bool StringHelper::StartsWithUnsafe(
        ssize_t length,
        const TChar* p,
        ssize_t lengthSub,
        const TChar* sub
    ) noexcept
    {
        if (lengthSub > length) return false;

        const TChar* end = p + lengthSub;

        while (p != end) {
            if (*p != *sub) return false;
            ++p;
            ++sub;
        }

        return true;
    }
}

#endif //!KLIB_KONGKONG_TEXT_STRINGHELPER_H