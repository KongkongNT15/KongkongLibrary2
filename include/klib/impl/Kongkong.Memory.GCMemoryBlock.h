#ifndef KLIB_KONGKONG_MEMORY_GCMEMORYBLOCK_H
#define KLIB_KONGKONG_MEMORY_GCMEMORYBLOCK_H

#include "base.h"
#include "Kongkong.ValueType.h"

namespace klib::Kongkong::Memory
{
    struct GCMemoryBlock final : public ValueType {
        friend GC;

    private:
        ssize_t m_length;
        void* m_pointer;
    public:

    };
}

#endif //!KLIB_KONGKONG_MEMORY_GCMEMORYBLOCK_H