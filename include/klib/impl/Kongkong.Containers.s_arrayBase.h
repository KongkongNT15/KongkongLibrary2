#ifndef KLIB_KONGKONG_CONTAINTERS_ARRAYBASE_H
#define KLIB_KONGKONG_CONTAINTERS_ARRAYBASE_H

#include "base.h"
#include "Kongkong.Containers.s_containerBase.h"
#include "Kongkong.Memory.GCObjectPointer.h"

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
        Memory::GCObjectPointer<T> m_p;

        explicit constexpr s_arrayBase(
            ssize_t length,
            Memory::GCObjectPointer<T> p
        ) noexcept;
    public:

        [[nodiscard]] constexpr bool StartsWith(
            T const& value
        ) const noexcept;
    };
}

namespace klib::Kongkong::Containers
{
    template <class T>
    constexpr bool s_arrayBase<T>::StartsWith(
        T const& value
    ) const noexcept
    {
        return ContainerHelper::StartsWithUnsafe(
            this->m_length,
            m_p.RawPointer(),
            value
        );
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_ARRAYBASE_H