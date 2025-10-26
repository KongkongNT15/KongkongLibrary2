#ifndef KLIB_KONGKONG_TEXT_GENERICFASTSTRINGBASE_H
#define KLIB_KONGKONG_TEXT_GENERICFASTSTRINGBASE_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Text.StringHelper.h"

#include <iosfwd>

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    struct GenericFastStringBase : public ValueType {
    public:
        /// <summary>
        /// 要素型
        /// </summary>
        using ElementType = typename TChar;

    protected:
        /// <summary>
        /// 参照する文字列の長さ
        /// </summary>
        ssize_t m_length;

        /// <summary>
        /// 文字列へのポインター
        /// </summary>
        const ElementType* m_p;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        GenericFastStringBase(
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 各メンバーの初期化
        /// </summary>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        explicit constexpr GenericFastStringBase(
            ssize_t length,
            const ElementType* p
        );

        GenericFastStringBase(GenericFastStringBase const&) = default;
        GenericFastStringBase(GenericFastStringBase&&) = default;

        GenericFastStringBase& operator=(GenericFastStringBase const&) = default;
        GenericFastStringBase& operator=(GenericFastStringBase&&) = default;

    public:
        /// <summary>
        /// IndexOf()で要素が見つからなかったときの戻り値
        /// </summary>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;

        /// <summary>
        /// 指定した番号の文字を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>文字への参照</returns>
        [[nodiscard]] constexpr ElementType const& operator[](
            ssize_t index
        ) const noexcept;

        [[nodiscard]] constexpr const ElementType* begin() const noexcept;
        [[nodiscard]] constexpr const ElementType* end() const noexcept;

        /// <summary>
        /// 指定したインデックスの文字を取得
        /// </summary>
        /// <param name="index">インデックス</param>
        /// <returns>指定したインデックスの文字</returns>
        /// <exception cref="ArgumentOutOfRangeException">indexが範囲外の時</exception>
        [[nodiscard]] constexpr ElementType const& At(
            ssize_t index
        ) const;

        /// <summary>
        /// 文字列に指定の文字が含まれるかを判定
        /// </summary>
        /// <param name="c">指定する文字</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool Contains(
            ElementType c
        ) const noexcept;

        /// <summary>
        /// 文字列に指定の部分文字列が含まれるかを判定
        /// </summary>
        /// <param name="subString">部分文字列</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool Contains(
            GenericFastStringBase const& subString
        ) const noexcept;

        /// <summary>
        /// 文字列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr const ElementType* Data() const noexcept;

        /// <summary>
        /// 文字列が指定した文字で終了するかを判定
        /// </summary>
        /// <param name="c">指定する文字</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool EndsWith(
            ElementType c
        ) const noexcept;

        /// <summary>
        /// 文字列が指定した部分文字列で終了するかを判定
        /// </summary>
        /// <param name="subString">部分文字列</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool EndsWith(
            GenericFastStringBase const & subString
        ) const noexcept;

        /// <summary>
        /// この文字列のビューを取得
        /// </summary>
        [[nodiscard]] constexpr GenericStringView<TChar> GetView() const noexcept;

        /// <summary>
        /// 文字列中の指定の文字の要素番号を取得
        /// </summary>
        /// <param name="c">指定する文字</param>
        /// <returns>指定した文字がある要素番号 見つからない場合はNotFound()</returns>
        [[nodiscard]] constexpr ssize_t IndexOf(
            ElementType c
        ) const noexcept;

        /// <summary>
        /// 文字列が空かを判定
        /// </summary>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool IsEmpty() const noexcept;

        /// <summary>
        /// 文字列の長さを取得
        /// </summary>
        [[nodiscard]] constexpr ssize_t Length() const noexcept;

        /// <summary>
        /// 文字列が指定した文字で始まるかを判定
        /// </summary>
        /// <param name="c">指定する文字</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool StartsWith(
            ElementType c
        ) const noexcept;

        /// <summary>
        /// 文字列が指定した部分文字列で始まるかを判定
        /// </summary>
        /// <param name="subString">部分文字列</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool StartsWith(
            GenericFastStringBase const& subString
        ) const noexcept;

        [[nodiscard]] String ToString() const;
    };

    //演算子の引数が参照なのは派生クラスがあるから

    /// <summary>
    /// 2つの文字列の値がすべて等しいかを判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr bool operator==(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept;

    /// <summary>
    /// 2つの文字列の値が等しくないかを判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr bool operator!=(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept;

    /// <summary>
    /// 辞書順でleftがrightより手前かを判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr bool operator<(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept;

    /// <summary>
    /// 辞書順でleftがrightより手前か等しいかを判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr bool operator<=(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept;

    /// <summary>
    /// 辞書順でleftがrightより後かを判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr bool operator>(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
        ) noexcept;

    /// <summary>
    /// 辞書順でleftがrightより後か等しいかを判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr bool operator>=(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept;

    /// <summary>
    /// 2つの文字列の順番を判定
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    /// <param name="left">文字列</param>
    /// <param name="right">文字列</param>
    /// <returns>判定結果</returns>
    template <CChar TChar>
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept;
}

namespace std
{
    /// <summary>
    /// 文字列をストリームに出力
    /// </summary>
    /// <param name="out">出力先</param>
    /// <param name="view">出力する文字列</param>
    /// <returns>outの参照</returns>
    ostream& operator<<(
        ostream& out,
        ::klib::Kongkong::Text::FastCharStringBase const& view
    );
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    consteval ssize_t GenericFastStringBase<TChar>::NotFound() noexcept
    {
        return StringHelper::NotFound();
    }

    template <CChar TChar>
    constexpr typename GenericFastStringBase<TChar>::ElementType const&
        GenericFastStringBase<TChar>::operator[](ssize_t index) const noexcept
    {
        return m_p[index];
    }

    template <CChar TChar>
    constexpr const typename GenericFastStringBase<TChar>::ElementType*
    GenericFastStringBase<TChar>::begin() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr const typename GenericFastStringBase<TChar>::ElementType*
    GenericFastStringBase<TChar>::end() const noexcept
    {
        return m_p + m_length;
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::Contains(
        ElementType c
    ) const noexcept
    {
        return StringHelper::ContainsUnsafe(
            m_length,
            m_p,
            c
        );
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::Contains(
        GenericFastStringBase<TChar> const& subString
    ) const noexcept
    {
        return StringHelper::ContainsUnsafe(
            m_length,
            m_p,
            subString.m_length,
            subString.m_p
        );
    }

    template <CChar TChar>
    constexpr const typename GenericFastStringBase<TChar>::ElementType*
    GenericFastStringBase<TChar>::Data() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::EndsWith(
        ElementType c
    ) const noexcept
    {
        return StringHelper::EndsWithUnsafe(
            m_length,
            m_p,
            c
        );
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::EndsWith(
        GenericFastStringBase<TChar> const& subString
    ) const noexcept
    {
        return StringHelper::EndsWithUnsafe(
            m_length,
            m_p,
            subString.m_length,
            subString.m_p
        );
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::IsEmpty() const noexcept
    {
        return m_length != 0;
    }

    template <CChar TChar>
    constexpr ssize_t GenericFastStringBase<TChar>::Length() const noexcept
    {
        return m_length;
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::StartsWith(
        ElementType c
    ) const noexcept
    {
        return StringHelper::StartsWithUnsafe(
            m_length,
            m_p,
            c
        );
    }

    template <CChar TChar>
    constexpr bool GenericFastStringBase<TChar>::StartsWith(
        GenericFastStringBase<TChar> const& subString
    ) const noexcept
    {
        return StringHelper::StartsWithUnsafe(
            m_length,
            m_p,
            subString.m_length,
            subString.m_p
        );
    }

    template <CChar TChar>
    constexpr bool operator==(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return StringHelper::IsEqualsUnsafe(
            left.Length(),
            left.Data(),
            right.Length(),
            right.Data()
        );
    }

    template <CChar TChar>
    constexpr bool operator!=(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return !(left == right);
    }

    template <CChar TChar>
    constexpr bool operator<(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return StringHelper::LessThanUnsafe(
            left.Length(),
            left.Data(),
            right.Length(),
            right.Data()
        );
    }

    template <CChar TChar>
    constexpr bool operator<=(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return !(left > right);
    }

    template <CChar TChar>
    constexpr bool operator>(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return StringHelper::GreaterThanUnsafe(
            left.Length(),
            left.Data(),
            right.Length(),
            right.Data()
        );
    }

    template <CChar TChar>
    constexpr bool operator>=(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return !(left < right);
    }

    template <CChar TChar>
    constexpr ::std::strong_ordering operator<=>(
        GenericFastStringBase<TChar> const& left,
        GenericFastStringBase<TChar> const& right
    ) noexcept
    {
        return StringHelper::CompareUnsafe(
            left.Length(),
            left.Data(),
            right.Length(),
            right.Data()
        );
    }
}

#include "Kongkong.ArgumentOutOfRangeException.h"

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr typename GenericFastStringBase<TChar>::ElementType const&
    GenericFastStringBase<TChar>::At(
        ssize_t index
    ) const
    {
        if (index < 0 || m_length <= index) [[unlikely]] {
            throw ArgumentOutOfRangeException(u"指定したインデックスが範囲外です");
        }

        return m_p[index];
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICFASTSTRINGBASE_H