#ifndef KLIB_KONGKONG_GC_H
#define KLIB_KONGKONG_GC_H

#include "base.h"

namespace klib::Kongkong
{
    /// <summary>
    /// ガベージコレクション
    /// </summary>
    class GC final {
    private:
        static bool s_isInitialized;
        static ssize_t s_length;
        static void* s_pointer;
    public:

        KLIB_STATIC_CLASS(GC);

        [[nodiscard]] static Memory::GCPointer Alloc(
            ssize_t size,
            Memory::GCMemoryPolicy policy
        );

        static ErrorCode Close() noexcept;

        /// <summary>
        /// GCの初期化
        /// </summary>
        /// <returns></returns>
        static ErrorCode Initialize(
            ssize_t blockSize
        ) noexcept;

        template <class TClass, class... Args>
        [[nodiscard]] static Memory::GCObjectPointer<TClass> New(
            Args&&... args
        );
    };
}

#include "Kongkong.Memory.GCPointer.h"
#include "Kongkong.Memory.GCObjectPointer.h"

namespace klib::Kongkong
{

}

#endif //!KLIB_KONGKONG_GC_H