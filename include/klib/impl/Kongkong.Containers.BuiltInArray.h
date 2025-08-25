#ifndef KLIB_KONGKONG_CONTAINTERS_BUILTINARRAY_H
#define KLIB_KONGKONG_CONTAINTERS_BUILTINARRAY_H

#include "base.h"
#include "Kongkong.ValueType.h"

namespace klib::Kongkong::Containers
{
    /// <summary>
    /// 組み込み配列
    /// </summary>
    /// <typeparam name="T">要素型</typeparam>
    /// <typeparam name="N">要素数</typeparam>
    template <class T, ssize_t N>
    struct BuiltInArray final : public ValueType {
    public:
        /// <summary>
        /// 要素型
        /// </summary>
        using ElementType = typename ::std::remove_cvref<T>;

        /// <summary>
        /// 配列本体
        /// </summary>
        ElementType Arr[N];

        /// <summary>
        /// 最大要素数を取得
        /// </summary>
        [[nodiscard]] static consteval ssize_t Capacity() noexcept;

        [[nodiscard]] static consteval bool IsEmpty() noexcept;

        /// <summary>
        /// 要素数を取得
        /// </summary>
        [[nodiscard]] static consteval ssize_t Length() noexcept;

        /// <summary>
        /// 要素を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>要素の参照</returns>
        [[nodiscard]] constexpr ElementType& operator[](
            ssize_t index
        ) noexcept;

        /// <summary>
        /// 要素を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>要素の参照</returns>
        [[nodiscard]] constexpr ElementType const& operator[](
            ssize_t index
        ) const noexcept;

        [[nodiscard]] constexpr ElementType* begin() noexcept;
        [[nodiscard]] constexpr const ElementType* begin() const noexcept;
        [[nodiscard]] constexpr ElementType* end() noexcept;
        [[nodiscard]] constexpr const ElementType* end() const noexcept;

        /// <summary>
        /// 配列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr ElementType* Data() noexcept;

        /// <summary>
        /// 配列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr const ElementType* Data() const noexcept;
    };
}

namespace klib::Kongkong::Containers
{
    template <class T, ssize_t N>
    consteval ssize_t BuiltInArray<T, N>::Capacity() noexcept
    {
        return N;
    }

    template <class T, ssize_t N>
    consteval bool BuiltInArray<T, N>::IsEmpty() noexcept
    {
        return false;
    }

    template <class T, ssize_t N>
    consteval ssize_t BuiltInArray<T, N>::Length() noexcept
    {
        return N;
    }

    template <class T, ssize_t N>
    constexpr BuiltInArray<T, N>::ElementType& BuiltInArray<T, N>::operator[](
        ssize_t index
    ) noexcept
    {
        return Arr[index];
    }

    template <class T, ssize_t N>
    constexpr BuiltInArray<T, N>::ElementType const& BuiltInArray<T, N>::operator[](
        ssize_t index
        ) const noexcept
    {
        return Arr[index];
    }

    template <class T, ssize_t N>
    constexpr BuiltInArray<T, N>::ElementType* BuiltInArray<T, N>::begin() noexcept
    {
        return Data();
    }

    template <class T, ssize_t N>
    constexpr const BuiltInArray<T, N>::ElementType* BuiltInArray<T, N>::begin() const noexcept
    {
        return Data();
    }

    template <class T, ssize_t N>
    constexpr BuiltInArray<T, N>::ElementType* BuiltInArray<T, N>::end() noexcept
    {
        return Arr + N;
    }

    template <class T, ssize_t N>
    constexpr const BuiltInArray<T, N>::ElementType* BuiltInArray<T, N>::end() const noexcept
    {
        return Arr + N;
    }

    template <class T, ssize_t N>
    constexpr BuiltInArray<T, N>::ElementType* BuiltInArray<T, N>::Data() noexcept
    {
        return Arr;
    }

    template <class T, ssize_t N>
    constexpr const BuiltInArray<T, N>::ElementType* BuiltInArray<T, N>::Data() const noexcept
    {
        return Arr;
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_BUILTINARRAY_H