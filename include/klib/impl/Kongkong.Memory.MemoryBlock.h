#ifndef KLIB_KONGKONG_MEMORY_MEMORYBLOCK_H
#define KLIB_KONGKONG_MEMORY_MEMORYBLOCK_H

#include "base.h"
#include "Kongkong.ValueType.h"

namespace klib::Kongkong::Memory
{
    struct MemoryBlock : public ValueType {
    private:
        ssize_t m_length;
        void* m_pointer;
        
    public:

        constexpr MemoryBlock(
            ssize_t length,
            void* p
        ) noexcept;
    };
}

#endif //!KLIB_KONGKONG_MEMORY_MEMORYBLOCK_H