#ifndef KLIB_KONGKONG_ARGUMENTEXCEPTION_H
#define KLIB_KONGKONG_ARGUMENTEXCEPTION_H

#include "base.h"
#include "Kongkong.Exception.h"

namespace klib::Kongkong
{
	/// <summary>
	/// 引数エラー
	/// </summary>
	struct ArgumentException : public Exception {
		using Exception::Exception;
	};
}

#endif //!KLIB_KONGKONG_ARGUMENTEXCEPTION_H