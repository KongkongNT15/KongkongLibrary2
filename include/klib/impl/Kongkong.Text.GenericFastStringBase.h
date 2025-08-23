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
		using ElementType = TChar;

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
		[[nodiscard]] constexpr const ElementType* begin() const noexcept;
		[[nodiscard]] constexpr const ElementType* end() const noexcept;

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
		/// 文字列の長さを取得
		/// </summary>
		[[nodiscard]] constexpr ssize_t Length() const noexcept;

		[[nodiscard]] String ToString() const;
	};

	//演算子の引数が参照なのは派生クラスがあるから

	/// <summary>
	/// 2つの文字列の値がすべて等しいかを判定
	/// </summary>
	/// <typeparam name="TChar">文字型</typeparam>
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="left">文字列ビュー</param>
	/// <param name="right">文字列ビュー</param>
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
	/// <param name="view">出力する文字列ビュー</param>
	/// <returns>outの参照</returns>
	ostream& operator<<(ostream& out, ::klib::Kongkong::Text::FastCharStringBase const& view);
}

namespace klib::Kongkong::Text
{
	template <CChar TChar>
	constexpr const GenericFastStringBase<TChar>::ElementType* GenericFastStringBase<TChar>::begin() const noexcept
	{
		return m_p;
	}

	template <CChar TChar>
	constexpr const GenericFastStringBase<TChar>::ElementType* GenericFastStringBase<TChar>::end() const noexcept
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
	constexpr const GenericFastStringBase<TChar>::ElementType* GenericFastStringBase<TChar>::Data() const noexcept
	{
		return m_p;
	}

	template <CChar TChar>
	constexpr ssize_t GenericFastStringBase<TChar>::Length() const noexcept
	{
		return m_length;
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

#endif //!KLIB_KONGKONG_TEXT_GENERICFASTSTRINGBASE_H