#ifndef KLIB_KONGKONG_MEMORY_GCMEMORYPOLICY_H
#define KLIB_KONGKONG_MEMORY_GCMEMORYPOLICY_H

#include "base.h"

namespace klib::Kongkong::Memory
{
    enum struct GCMemoryPolicy {
        Movable,
        Pinned
    };
}

#endif //!KLIB_KONGKONG_MEMORY_GCMEMORYPOLICY_H