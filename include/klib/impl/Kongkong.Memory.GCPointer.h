#ifndef KLIB_KONGKONG_MEMORY_GCPOINTER_H
#define KLIB_KONGKONG_MEMORY_GCPOINTER_H

#include "base.h"
#include "Kongkong.PointerType.h"

namespace klib::Kongkong::Memory
{
    class GCPointer final : PointerType {
        friend GC;
        private:
        ssize_t m_hashCode;

        public:

        [[nodiscard]] constexpr ssize_t HashCode() const noexcept;

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
    constexpr ssize_t GCPointer::HashCode() const noexcept
    {
        return m_hashCode;
    }

    constexpr bool operator==(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() == right.HashCode();
    }

    constexpr bool operator!=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() != right.HashCode();
    }

    constexpr bool operator<(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() < right.HashCode();
    }

    constexpr bool operator<=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() <= right.HashCode();
    }

    constexpr bool operator>(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() > right.HashCode();
    }

    constexpr bool operator>=(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() >= right.HashCode();
    }

    constexpr ::std::strong_ordering operator<=>(
        GCPointer const& left,
        GCPointer const& right
    ) noexcept
    {
        return left.HashCode() <=> right.HashCode();
    }
}

#endif //!KLIB_KONGKONG_MEMORY_GCPOINTER_H