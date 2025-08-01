#ifndef KLIB_KONGKONG_TEXT_GENERICSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTRING_H

#include "base.h"
#include "Kongkong.Object.h"

namespace klib::Kongkong::Text
{
	/// <summary>
	/// 文字列クラス
	/// </summary>
	/// <typeparam name="TChar">文字型</typeparam>
	template <CCharType TChar>
	class GenericString : public Object {
	protected:

		struct ImplType : public Object::ImplType {
		protected:
			ssize_t m_length;
			TChar* m_p;

		public:
			/// <summary>
			/// 文字列の長さを取得
			/// </summary>
			/// <returns>文字列の長さ</returns>
			[[nodiscard]] constexpr ssize_t Length() const noexcept;
		};

	public:
		KLIB_KONGKONG_OBJECT_OMAJINAI(GenericString, Object)
	};
}

namespace klib::Kongkong::Text
{
	template <CCharType TChar>
	constexpr ssize_t GenericString<TChar>::ImplType::Length() const noexcept
	{
		return m_length;
	}
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRING_H