#ifndef KLIB_KONGKONG_ARGUMENTOUTOFRANGEEXCEPTION_H
#define KLIB_KONGKONG_ARGUMENTOUTOFRANGEEXCEPTION_H

#include "base.h"
#include "Kongkong.ArgumentException.h"

namespace klib::Kongkong
{
	/// <summary>
	/// 引数が範囲外
	/// </summary>
	struct ArgumentOutOfRangeException : public ArgumentException {
		using ArgumentException::ArgumentException;
	};
}

#endif //!KLIB_KONGKONG_ARGUMENTOUTOFRANGEEXCEPTION_H