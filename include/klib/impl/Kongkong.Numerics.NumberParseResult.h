#ifndef KLIB_KONGKONG_NUMERICS_NUMBERPARSERESULT_H
#define KLIB_KONGKONG_NUMERICS_NUMBERPARSERESULT_H

#include "base.h"

namespace klib::Kongkong::Numerics
{
    template <class T>
    struct NumberParseResult {
    public:
        using NumberType = typename T;

        NumberType Value;

        bool IsSuccess;
    };
}

#endif //!KLIB_KONGKONG_NUMERICS_NUMBERPARSERESULT_H