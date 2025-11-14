#ifndef KLIB_KONGKONG_TEXT_GENERICSTATICFASTSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTATICFASTSTRING_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Text.StringHelper.h"
#include "Kongkong.Text.GenericStringView.h"

namespace klib::Kongkong::Text
{
	template <CChar TChar, ssize_t N>
	struct GenericStaticFastString final : public ValueType {
	public:
		using ElementType = TChar;
	private:

		/// <summary>
		/// 文字配列
		/// </summary>
		ElementType m_arr[N];

	public:

        /// <summary>
        /// 文字配列の要素数を取得
        /// </summary>
        [[nodiscard]] static consteval ssize_t Capacity() noexcept;

        /// <summary>
        /// 文字列が空かを判定
        /// </summary>
        /// <returns>判定結果</returns>
        [[nodiscard]] static consteval bool IsEmpty() noexcept;

        /// <summary>
        /// 文字列の長さを取得
        /// </summary>
        [[nodiscard]] static consteval ssize_t Length() noexcept;

        /// <summary>
        /// IndexOf()で要素が見つからなかったときの戻り値
        /// </summary>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;

        /// <summary>
        /// 文字列リテラルから作成
        /// </summary>
        /// <param name="arr">文字列リテラル</param>
        consteval GenericStaticFastString(
            const ElementType(&arr)[N]
        ) noexcept;

        /// <summary>
        /// 指定した番号の文字を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>文字への参照</returns>
        [[nodiscard]] constexpr ElementType const& operator[](
            ssize_t index
        ) const noexcept;

        /// <summary>
        /// 指定した番号の文字を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>文字への参照</returns>
        [[nodiscard]] constexpr ElementType& operator[](
            ssize_t index
        ) noexcept;

        [[nodiscard]] constexpr ElementType* begin() noexcept;
        [[nodiscard]] constexpr const ElementType* begin() const noexcept;
        [[nodiscard]] constexpr ElementType* end() noexcept;
        [[nodiscard]] constexpr const ElementType* end() const noexcept;

        /// <summary>
        /// Cスタイル文字列を取得
        /// </summary>
        [[nodiscard]] constexpr const ElementType* c_str() const noexcept;

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
            GenericFastStringBase<TChar> const& subString
        ) const noexcept;

        /// <summary>
        /// 文字列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr ElementType* Data() noexcept;

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
            GenericFastStringBase<TChar> const& subString
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
            GenericFastStringBase<TChar> const& subString
        ) const noexcept;

        [[nodiscard]] String ToString() const;
	};

	/// <summary>
	/// StaticFastString<>として使用する
	/// StaticFastStringのヘルパークラス
	/// </summary>
	template <>
	struct GenericStaticFastString<char16_t, 0> final {
	private:
	public:

		KLIB_STATIC_CLASS(GenericStaticFastString);

        /// <summary>
        /// IndexOf()で要素が見つからなかったときの戻り値
        /// </summary>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;

		template <CChar TChar, ssize_t N>
		[[nodiscard]] static consteval GenericStaticFastString<TChar, N> FromLiteral(
			const TChar(&arr)[N]
		) noexcept;
	};
}

namespace klib::Kongkong::Text
{
    template <CChar TChar, ssize_t N>
    consteval ssize_t GenericStaticFastString<TChar, N>::Capacity() noexcept
    {
        return N;
    }

    template <CChar TChar, ssize_t N>
    consteval bool GenericStaticFastString<TChar, N>::IsEmpty() noexcept
    {
        return N == 1;
    }

    template <CChar TChar, ssize_t N>
    consteval ssize_t GenericStaticFastString<TChar, N>::Length() noexcept
    {
        return N - 1;
    }

    template <CChar TChar, ssize_t N>
    consteval ssize_t GenericStaticFastString<TChar, N>::NotFound() noexcept
    {
        return StringHelper::NotFound();
    }

    template <CChar TChar, ssize_t N>
    consteval GenericStaticFastString<TChar, N>::GenericStaticFastString(
        const ElementType(&arr)[N]
    ) noexcept
    {
        for (ssize_t i = 0; i < N; i++) {
            m_arr[i] = arr[i];
        }
    }

    template <CChar TChar, ssize_t N>
    constexpr GenericStaticFastString<TChar, N>::ElementType&
    GenericStaticFastString<TChar, N>::operator[](ssize_t index) noexcept
    {
        return m_arr[index];
    }

    template <CChar TChar, ssize_t N>
    constexpr GenericStaticFastString<TChar, N>::ElementType const&
    GenericStaticFastString<TChar, N>::operator[](ssize_t index) const noexcept
    {
        return m_arr[index];
    }

    template <CChar TChar, ssize_t N>
    constexpr GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::begin() noexcept
    {
        return m_arr;
    }

    template <CChar TChar, ssize_t N>
    constexpr const GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::begin() const noexcept
    {
        return m_arr;
    }

    template <CChar TChar, ssize_t N>
    constexpr GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::end() noexcept
    {
        return m_arr + (N - 1);
    }

    template <CChar TChar, ssize_t N>
    constexpr const GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::end() const noexcept
    {
        return m_arr + (N - 1);
    }

    template <CChar TChar, ssize_t N>
    constexpr const GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::c_str() const noexcept
    {
        return m_arr;
    }

    template <CChar TChar, ssize_t N>
    constexpr bool GenericStaticFastString<TChar, N>::Contains(
        ElementType c
    ) const noexcept
    {
        return StringHelper::ContainsUnsafe(
            N - 1,
            m_arr,
            c
        );
    }

    template <CChar TChar, ssize_t N>
    constexpr bool GenericStaticFastString<TChar, N>::Contains(
        GenericFastStringBase<TChar> const& subString
    ) const noexcept
    {
        return StringHelper::ContainsUnsafe(
            N - 1,
            m_arr,
            subString.Length(),
            subString.Data()
        );
    }

    template <CChar TChar, ssize_t N>
    constexpr GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::Data() noexcept
    {
        return m_arr;
    }

    template <CChar TChar, ssize_t N>
    constexpr const GenericStaticFastString<TChar, N>::ElementType*
    GenericStaticFastString<TChar, N>::Data() const noexcept
    {
        return m_arr;
    }

    template <CChar TChar, ssize_t N>
    constexpr bool GenericStaticFastString<TChar, N>::EndsWith(
        ElementType c
    ) const noexcept
    {
        return StringHelper::EndsWithUnsafe(
            N - 1,
            m_arr,
            c
        );
    }

    template <CChar TChar, ssize_t N>
    constexpr bool GenericStaticFastString<TChar, N>::EndsWith(
        GenericFastStringBase<TChar> const& subString
    ) const noexcept
    {
        return StringHelper::EndsWithUnsafe(
            N - 1,
            m_arr,
            subString.Length(),
            subString.Data()
        );
    }

	template <CChar TChar, ssize_t N>
	constexpr GenericStringView<TChar>
    GenericStaticFastString<TChar, N>::GetView() const noexcept
	{
		return GenericStringView<TChar>::CreateUnsafe(
			N - 1,
			m_arr
		);
	}

    template <CChar TChar, ssize_t N>
    constexpr bool GenericStaticFastString<TChar, N>::StartsWith(
        ElementType c
    ) const noexcept
    {
        return StringHelper::StartsWithUnsafe(
            N - 1,
            m_arr,
            c
        );
    }

    template <CChar TChar, ssize_t N>
    constexpr bool GenericStaticFastString<TChar, N>::StartsWith(
        GenericFastStringBase<TChar> const& subString
    ) const noexcept
    {
        return StringHelper::StartsWithUnsafe(
            N - 1,
            m_arr,
            subString.Length(),
            subString.Data()
        );
    }

    consteval ssize_t GenericStaticFastString<char16_t, 0>::NotFound() noexcept
    {
        return StringHelper::NotFound();
    }

    template <CChar TChar, ssize_t N>
    consteval GenericStaticFastString<TChar, N>
    GenericStaticFastString<char16_t, 0>::FromLiteral(
        const TChar(&arr)[N]
    ) noexcept
    {
        return GenericStaticFastString<TChar, N>(arr);
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTATICFASTSTRING_H