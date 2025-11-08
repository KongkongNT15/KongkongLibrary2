#ifndef KLIB_KONGKONG_MEMORY_GCOBJECTPOINTER_H
#define KLIB_KONGKONG_MEMORY_GCOBJECTPOINTER_H

#include "base.h"
#include "Kongkong.PointerType.h"
#include "Kongkong.Memory.GCPointer.h"

namespace klib::Kongkong::Memory
{
    template <class T>
    class GCObjectPointer final : public PointerType {
        friend GCPointer;
    private:
        GCPointer m_pointer;

        GCObjectPointer(
            GCPointer pointer
        );

    public:

        constexpr GCObjectPointer(
            ::std::nullptr_t
        ) noexcept;

        [[nodiscard]] constexpr T& operator[](
            ssize_t index
        ) const noexcept;

        [[nodiscard]] constexpr T* RawPointer() const noexcept;
    };
}

namespace klib::Kongkong::Memory
{
    template <class T>
    constexpr GCObjectPointer<T>::GCObjectPointer(
        ::std::nullptr_t
    ) noexcept
        : m_pointer(nullptr)
    {
    }

    template <class T>
    GCObjectPointer<T> GCPointer::Cast() const noexcept
    {
        return GCObjectPointer<T>(*this);
    }

    template <class T>
    GCObjectPointer<T>::GCObjectPointer(
        GCPointer pointer
    )
        : m_pointer(::std::move(pointer))
    {
    }

    template <class T>
    constexpr T& GCObjectPointer<T>::operator[](
        ssize_t index
    ) const noexcept
    {
        return RawPointer()[index];
    }

    template <class T>
    constexpr T* GCObjectPointer<T>::RawPointer() const noexcept
    {
        return static_cast<T*>(m_pointer.RawPointer());
    }
}

#endif //!KLIB_KONGKONG_MEMORY_GCOBJECTPOINTER_H