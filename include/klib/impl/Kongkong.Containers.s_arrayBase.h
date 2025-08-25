#ifndef KLIB_KONGKONG_CONTAINTERS_ARRAYBASE_H
#define KLIB_KONGKONG_CONTAINTERS_ARRAYBASE_H

#include "base.h"
#include "Kongkong.Containers.s_containerBase.h"

namespace klib::Kongkong::Containers
{
    /// <summary>
    /// 
    /// </summary>
    /// <typeparam name="T"></typeparam>
    template <class T>
    struct s_arrayBase : public s_containerBase {
    public:
        
    protected:
        T* m_p;

        explicit constexpr s_arrayBase(
            ssize_t length,
            T* p
        ) noexcept;
    public:

        
    };
}

#endif //!KLIB_KONGKONG_CONTAINTERS_ARRAYBASE_H