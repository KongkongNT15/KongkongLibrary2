#ifndef KLIB_KONGKONG_TEXT_STATICSTRINGHELPERRESULT_H
#define KLIB_KONGKONG_TEXT_STATICSTRINGHELPERRESULT_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Text.GenericStaticString.h"

namespace klib::Kongkong::Text
{
	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="TChar">文字型</typeparam>
	template <CCharType TChar, ssize_t N>
	struct StaticStringHelperResult : public ValueType {
	private:
		GenericStaticString<TChar> m_ref;
		GenericStaticString<TChar>::ImplType<N> m_result;
	public:

		constexpr StaticStringHelperResult() noexcept;

		/// <summary>
		/// 文字列を取得
		/// </summary>
		/// <returns>文字列インスタンス</returns>
		[[nodiscard]] GenericStaticString<TChar>& Reference() noexcept;

		/// <summary>
		/// 文字列を取得
		/// </summary>
		/// <returns>文字列インスタンス</returns>
		[[nodiscard]] GenericStaticString<TChar> const& Reference() const noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] ::klib::Kongkong::String ToString() const;
	};
}

#endif //!KLIB_KONGKONG_TEXT_STATICSTRINGHELPERRESULT_H