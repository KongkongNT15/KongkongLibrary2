#ifndef KLIB_KONGKONG_MEMORY_GCPOINTER_H
#define KLIB_KONGKONG_MEMORY_GCPOINTER_H

#include "base.h"
#include "Kongkong.PointerType.h"

namespace klib::Kongkong::Memory
{
    class GCPointer final : PointerType {
        friend GC;
    private:
        void* m_pointer;

        constexpr GCPointer(
            void* pointer
        ) noexcept;

    public:

        [[nodiscard]] static GCPointer Null() noexcept;

        constexpr GCPointer(
            ::std::nullptr_t
        ) noexcept;

        GCPointer(
            GCPointer const& other
        );

        constexpr GCPointer(
            GCPointer&& other
        ) noexcept;

        ~GCPointer();

        GCPointer& operator=(
            ::std::nullptr_t
        ) noexcept;

        GCPointer& operator=(
            GCPointer const& other
        );

        GCPointer& operator=(
            GCPointer&& other
        );

        [[nodiscard]] void* RawPointer() const noexcept;
    };

    [[nodiscard]] constexpr bool operator==(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator!=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator<(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator<=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator>(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator>=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;

    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept;
}

namespace klib::Kongkong::Memory
{
    constexpr bool operator==(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() == right.RawPointer();
    }

    constexpr bool operator!=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() != right.RawPointer();
    }

    constexpr bool operator<(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() < right.RawPointer();
    }

    constexpr bool operator<=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() <= right.RawPointer();
    }

    constexpr bool operator>(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() > right.RawPointer();
    }

    constexpr bool operator>=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() >= right.RawPointer();
    }

    constexpr ::std::strong_ordering operator<=>(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.RawPointer() <=> right.RawPointer();
    }
}

#endif //!KLIB_KONGKONG_MEMORY_GCPOINTER_H