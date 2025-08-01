#ifndef KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H

#include "base.h"
#include "Kongkong.Text.GenericString.h"

namespace klib::Kongkong::Text
{
	/// <summary>
	/// 静的領域に配置される文字列
	/// </summary>
	/// <typeparam name="TChar">文字型</typeparam>
	template <CCharType TChar>
	class GenericStaticString : public GenericString<TChar> {
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="N">配列の長さ</typeparam>
		template <ssize_t N>
		struct ImplType : public GenericString<TChar>::ImplType {
			
		};

		// ここのImplTypeは
		// KLIB_KONGKONG_OBJECT_OMAJINAI(GenericStaticString, GenericString<TChar>)
	};
}

#endif //! KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H