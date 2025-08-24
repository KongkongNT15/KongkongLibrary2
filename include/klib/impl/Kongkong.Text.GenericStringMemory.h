#ifndef KLIB_KONGKONG_TEXT_GENERICSTRINGMEMORY_H
#define KLIB_KONGKONG_TEXT_GENERICSTRINGMEMORY_H

#include "base.h"
#include "Kongkong.ValueType.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CChar TChar>
    struct GenericStringMemory final : public ValueType {
    private:
        /// <summary>
        /// 確保した領域の要素数
        /// </summary>
        ssize_t m_capacity;

        /// <summary>
        /// 確保した領域
        /// </summary>
        TChar* m_p;

        explicit constexpr GenericStringMemory(
            ssize_t capacity,
            TChar* p
        ) noexcept;
    public:

        /// <summary>
        /// nullptr
        /// </summary>
        [[nodiscard]] static constexpr GenericStringMemory Null() noexcept;

        /// <summary>
        /// メモリを確保
        /// </summary>
        /// <param name="capacity">NULL文字を含む文字列の長さ</param>
        /// <returns>確保されたメモリ</returns>
        /// <exception cref="MemoryAllocationException">メモリ確保に失敗したとき</exception>
        [[nodiscard]] static GenericStringMemory AllocWithCapacityUnsafe(
            ssize_t capacity
        );

        /// <summary>
        /// メモリを確保
        /// </summary>
        /// <param name="length">NULL文字を含まない文字列の長さ</param>
        /// <returns>確保されたメモリ</returns>
        /// <exception cref="MemoryAllocationException">メモリ確保に失敗したとき</exception>
        [[nodiscard]] static GenericStringMemory AllocWithLengthUnsafe(
            ssize_t length
        );

        /// <summary>
        /// 指定した場所の文字を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>文字の参照</returns>
        [[nodiscard]] constexpr TChar& operator[](
            ssize_t index
        ) const noexcept;

        [[nodiscard]] constexpr TChar* begin() const noexcept;
        [[nodiscard]] constexpr TChar* end() const noexcept;

        /// <summary>
        /// 確保した領域の要素数を取得
        /// </summary>
        [[nodiscard]] constexpr ssize_t Capacity() const noexcept;

        /// <summary>
        /// 領域を解放
        /// </summary>
        constexpr void DeleteUnsafe() const noexcept;

        /// <summary>
        /// 生ポインターを取得
        /// </summary>
        [[nodiscard]] constexpr TChar* Pointer() const noexcept;

        /// <summary>
        /// 末尾にNULL文字を追加
        /// </summary>
        constexpr void SetNullTerminatorUnsafe() const noexcept;
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr GenericStringMemory<TChar>::GenericStringMemory(
        ssize_t capacity,
        TChar* p
    ) noexcept
        : m_capacity(capacity)
        , m_p(p)
    {
    }

    template <CChar TChar>
    constexpr GenericStringMemory<TChar> GenericStringMemory<TChar>::Null() noexcept
    {
        return GenericStringMemory<TChar>(
            0,
            nullptr
        );
    }

    template <CChar TChar>
    GenericStringMemory<TChar> GenericStringMemory<TChar>::AllocWithLengthUnsafe(
        ssize_t length
    )
    {
        return AllocWithCapacityUnsafe(length + 1);
    }

    template <CChar TChar>
    constexpr TChar& GenericStringMemory<TChar>::operator[](
        ssize_t index
    ) const noexcept
    {
        return m_p[index];
    }

    template <CChar TChar>
    constexpr TChar* GenericStringMemory<TChar>::begin() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr TChar* GenericStringMemory<TChar>::end() const noexcept
    {
        return m_p + m_capacity;
    }

    template <CChar TChar>
    constexpr ssize_t GenericStringMemory<TChar>::Capacity() const noexcept
    {
        return m_capacity;
    }

    template <CChar TChar>
    constexpr void GenericStringMemory<TChar>::DeleteUnsafe() const noexcept
    {
        delete[] m_p, ::std::nothrow;
    }

    template <CChar TChar>
    constexpr TChar* GenericStringMemory<TChar>::Pointer() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr void GenericStringMemory<TChar>::SetNullTerminatorUnsafe() const noexcept
    {
        m_p[m_capacity - 1] = static_cast<TChar>('\0');
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRINGMEMORY_H