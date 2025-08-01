#ifndef KLIB_KONGKONG_INVALIDCASTEXCEPTION_H
#define KLIB_KONGKONG_INVALIDCASTEXCEPTION_H

#include "base.h"
#include "Kongkong.Exception.h"

namespace klib::Kongkong
{
	/// <summary>
	/// キャスト失敗時の例外
	/// </summary>
	struct InvalidCastException : public Exception {
		InvalidCastException() noexcept;
		using Exception::Exception;
	};
}

#endif //!KLIB_KONGKONG_INVALIDCASTEXCEPTION_H