#ifndef KLIB_KONGKONG_MEMORY_GCMEMORY_H
#define KLIB_KONGKONG_MEMORY_GCMEMORY_H

#include "base.h"
#include "Kongkong.PointerType.h"

namespace klib::Kongkong::Memory
{
    class GCMemory final : PointerType {
        private:
        ssize_t m_hashCode;

        public:

        [[nodiscard]] constexpr ssize_t HashCode() const noexcept;

        [[nodiscard]] void* RawPointer() const noexcept;
    };

    [[nodiscard]] constexpr bool operator==(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator!=(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator<(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator<=(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator>(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;

    [[nodiscard]] constexpr bool operator>=(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;

    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept;
}

namespace klib::Kongkong::Memory
{
    constexpr ssize_t GCMemory::HashCode() const noexcept
    {
        return m_hashCode;
    }

    constexpr bool operator==(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() == right.HashCode();
    }

    constexpr bool operator!=(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() != right.HashCode();
    }

    constexpr bool operator<(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() < right.HashCode();
    }

    constexpr bool operator<=(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() <= right.HashCode();
    }

    constexpr bool operator>(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() > right.HashCode();
    }

    constexpr bool operator>=(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() >= right.HashCode();
    }

    constexpr ::std::strong_ordering operator<=>(
        GCMemory const& left,
        GCMemory const& right
    ) noexcept
    {
        return left.HashCode() <=> right.HashCode();
    }
}

#endif //!KLIB_KONGKONG_MEMORY_GCMEMORY_H