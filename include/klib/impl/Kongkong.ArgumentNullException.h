#ifndef KLIB_KONGKONG_ARGUMENTNULLEXCEPTION_H
#define KLIB_KONGKONG_ARGUMENTNULLEXCEPTION_H

#include "base.h"
#include "Kongkong.ArgumentException.h"

namespace klib::Kongkong
{
    /// <summary>
    /// 引数がnullptr
    /// </summary>
    struct ArgumentNullException : public ArgumentException {
        using ArgumentException::ArgumentException;
    };
}

#endif //!KLIB_KONGKONG_ARGUMENTNULLEXCEPTION_H