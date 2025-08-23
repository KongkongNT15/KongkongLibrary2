#ifndef KLIB_KONGKONG_TEXT_GENERICSTRINGVIEW_H
#define KLIB_KONGKONG_TEXT_GENERICSTRINGVIEW_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.NonType.h"
#include "Kongkong.Text.StringHelper.h"

#include <iosfwd>

namespace klib::Kongkong::Text
{
	/// <summary>
	/// 文字列ビュー
	/// </summary>
	/// <typeparam name="TChar"></typeparam>
	template <CChar TChar>
	struct GenericStringView final : public ValueType {
	public:
		/// <summary>
		/// 要素型
		/// </summary>
		using ElementType = TChar;
	private:
		/// <summary>
		/// 参照する文字列の長さ
		/// </summary>
		ssize_t m_length;

		/// <summary>
		/// 文字列へのポインター
		/// </summary>
		const ElementType* m_p;

		/// <summary>
		/// 安全性を確認せずにオブジェクトを構築
		/// </summary>
		/// <param name="p">文字列へのポインター</param>
		/// <param name="nonType">使わない型</param>
		explicit constexpr GenericStringView(
			const ElementType* p,
			NonType nonType
		) noexcept;

		/// <summary>
		/// 安全性を確認せずにオブジェクトを構築
		/// </summary>
		/// <param name="length">参照する文字列の長さ</param>
		/// <param name="p">文字列へのポインター</param>
		/// <param name="nonType">使わない型</param>
		explicit constexpr GenericStringView(
			ssize_t length,
			const ElementType* p,
			NonType nonType
		) noexcept;

	public:

		/// <summary>
		/// 安全性を確認せずにオブジェクトを構築
		/// </summary>
		/// <param name="p">文字列へのポインター</param>
		/// <returns>構築されたオブジェクト</returns>
		KLIB_NODISCARD static constexpr GenericStringView CreateUnsafe(
			const ElementType* p
		) noexcept;

		/// <summary>
		/// 安全性を確認せずにオブジェクトを構築
		/// </summary>
		/// <param name="length">参照する文字列の長さ</param>
		/// <param name="p">文字列へのポインター</param>
		/// <returns>構築されたオブジェクト</returns>
		KLIB_NODISCARD static constexpr GenericStringView CreateUnsafe(
			ssize_t length,
			const ElementType* p
		) noexcept;

		KLIB_NODISCARD constexpr const ElementType* begin() const noexcept;
		KLIB_NODISCARD constexpr const ElementType* end() const noexcept;

		/// <summary>
		/// 文字列へのポインターを取得
		/// </summary>
		KLIB_NODISCARD constexpr const ElementType* Data() const noexcept;

		/// <summary>
		/// 文字列の長さを取得
		/// </summary>
		KLIB_NODISCARD constexpr ssize_t Length() const noexcept;
	};

	template <CChar TChar>
	KLIB_NODISCARD constexpr bool operator==(GenericStringView<TChar> left, GenericStringView<TChar> right) noexcept;
}

namespace klib::Kongkong::Text
{
	template <CChar TChar>
	constexpr GenericStringView<TChar>::GenericStringView(
		const ElementType* p,
		NonType
	) noexcept
		: m_length(StringHelper::GetLengthUnsafe(p))
		, m_p(p)
	{
	}

	template <CChar TChar>
	constexpr GenericStringView<TChar>::GenericStringView(
		ssize_t length,
		const ElementType* p,
		NonType
	) noexcept
		: m_length(length)
		, m_p(p)
	{
	}

	template <CChar TChar>
	constexpr GenericStringView<TChar> GenericStringView<TChar>::CreateUnsafe(
		const ElementType* p
	) noexcept
	{
		return GenericStringView<TChar>(p, {});
	}

	template <CChar TChar>
	constexpr GenericStringView<TChar> GenericStringView<TChar>::CreateUnsafe(
		ssize_t length,
		const ElementType* p
	) noexcept
	{
		return GenericStringView<TChar>(length, p, {});
	}

	template <CChar TChar>
	constexpr const GenericStringView<TChar>::ElementType* GenericStringView<TChar>::begin() const noexcept
	{
		return m_p;
	}

	template <CChar TChar>
	constexpr const GenericStringView<TChar>::ElementType* GenericStringView<TChar>::end() const noexcept
	{
		return m_p + m_length;
	}

	template <CChar TChar>
	constexpr const GenericStringView<TChar>::ElementType* GenericStringView<TChar>::Data() const noexcept
	{
		return m_p;
	}

	template <CChar TChar>
	constexpr ssize_t GenericStringView<TChar>::Length() const noexcept
	{
		return m_length;
	}

	template <CChar TChar>
	constexpr bool operator==(GenericStringView<TChar> left, GenericStringView<TChar> right) noexcept
	{
		return StringHelper::IsEqualsUnsafe(
			left.Length(),
			left.Data(),
			right.Length(),
			right.Data()
		);
	}

	template <CChar TChar>
	constexpr bool operator!=(GenericStringView<TChar> left, GenericStringView<TChar> right) noexcept
	{
		return !(left == right);
	}
}

namespace std
{
	ostream& operator<<(ostream& out, ::klib::Kongkong::Text::CharStringView view);
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRINGVIEW_H