#ifndef KLIB_KONGKONG_THREADING_MUTEX_H
#define KLIB_KONGKONG_THREADING_MUTEX_H

#include "base.h"
#include "Kongkong.HandleType.h"

#if KLIB_ENV_OTHER
    #include <mutex>
#endif

namespace klib::Kongkong::Threading
{
    /// <summary>
    /// Mutex
    /// </summary>
    class Mutex final : public HandleType {
    private:
#if KLIB_ENV_WINDOWS
        
        /// <summary>
        /// Mutexへのハンドル
        /// </summary>
        ::HANDLE m_handle;
#elif KLIB_ENV_UNIX

#elif KLIB_ENV_OTHER

#endif
    public:

        [[nodiscard]] static Mutex OpenExisting();
    };
}

#endif //!KLIB_KONGKONG_THREADING_MUTEX_H