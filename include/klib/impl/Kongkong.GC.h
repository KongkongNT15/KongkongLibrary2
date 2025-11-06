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

        static bool Close() noexcept;

        /// <summary>
        /// GCの初期化
        /// </summary>
        /// <returns></returns>
        static bool Initialize(
            
        ) noexcept;

        
    };
}

#endif //!KLIB_KONGKONG_GC_H