#ifndef KLIB_KONGKONG_CONTAINTERS_BUILTINARRAYLIST_H
#define KLIB_KONGKONG_CONTAINTERS_BUILTINARRAYLIST_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Containers.ContainerHelper.h"
#include "Kongkong.Containers.s_containerBase.h"

namespace klib::Kongkong::Containers
{
    /// <summary>
    /// 組み込み配列リスト
    /// </summary>
    /// <typeparam name="T">要素型</typeparam>
    /// <typeparam name="N">最大要素数</typeparam>
    template <class T, ssize_t N>
    struct BuiltInArrayList final : public ValueType, public s_containerBase {
    public:
        /// <summary>
        /// 要素型
        /// </summary>
        using ElementType = typename ::std::remove_cvref_t<T>;
    private:

        /// <summary>
        /// 配列
        /// </summary>
        uint8_t m_arr[N * sizeof(ElementType)];
    public:
        /// <summary>
        /// 最大要素数を取得
        /// </summary>
        [[nodiscard]] static consteval ssize_t Capacity() noexcept;

        /// <summary>
        /// 空のリストを作成
        /// </summary>
        constexpr BuiltInArrayList() noexcept;

        /// <summary>
        /// 要素をすべて破棄
        /// </summary>
        constexpr ~BuiltInArrayList();

        [[nodiscard]] constexpr ElementType* begin() noexcept;
        [[nodiscard]] constexpr const ElementType* begin() const noexcept;
        [[nodiscard]] constexpr ElementType* end() noexcept;
        [[nodiscard]] constexpr const ElementType* end() const noexcept;

        /// <summary>
        /// 末尾に要素をデフォルト構築
        /// </summary>
        /// <returns>要素を追加できたかどうか</returns>
        bool Append() noexcept(::std::is_nothrow_constructible_v<ElementType>) requires ::std::default_initializable<ElementType>;

        /// <summary>
        /// 末尾に要素をコピー構築
        /// </summary>
        /// <param name="value">追加する要素</param>
        /// <returns>要素を追加できたかどうか</returns>
        bool Append(
            ElementType const& value
        ) noexcept(::std::is_nothrow_copy_constructible_v<ElementType>) requires ::std::copy_constructible<ElementType>;

        /// <summary>
        /// 末尾に要素をムーブ構築
        /// </summary>
        /// <param name="value">追加する要素</param>
        /// <returns>要素を追加できたかどうか</returns>
        bool Append(
            ElementType&& value
        ) noexcept(::std::is_nothrow_move_constructible_v<ElementType>) requires ::std::move_constructible<ElementType>;

        /// <summary>
        /// 要素をすべて破棄
        /// </summary>
        constexpr void Clear() noexcept;

        /// <summary>
        /// 配列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr ElementType* Data() noexcept;

        /// <summary>
        /// 配列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr const ElementType* Data() const noexcept;

        /// <summary>
        /// 末尾に要素を直接構築
        /// </summary>
        /// <typeparam name="...Args">可変長引数</typeparam>
        /// <param name="...args">コンストラクタ引数</param>
        /// <returns>要素を追加できたかどうか</returns>
        template <class... Args>
        bool Emplace(
            Args&&... args
        ) noexcept(noexcept(ElementType(::std::forward<Args>(args)...)));

        


    };
}

namespace klib::Kongkong::Containers
{
    template <class T, ssize_t N>
    consteval ssize_t BuiltInArrayList<T, N>::Capacity() noexcept
    {
        return N;
    }

    template <class T, ssize_t N>
    constexpr BuiltInArrayList<T, N>::~BuiltInArrayList()
    {
        for (ElementType& element : *this) {
            element.~ElementType();
        }
    }

    template <class T, ssize_t N>
    constexpr BuiltInArrayList<T, N>::ElementType* BuiltInArrayList<T, N>::begin() noexcept
    {
        return Data();
    }

    template <class T, ssize_t N>
    constexpr const BuiltInArrayList<T, N>::ElementType* BuiltInArrayList<T, N>::begin() const noexcept
    {
        return Data();
    }

    template <class T, ssize_t N>
    constexpr BuiltInArrayList<T, N>::ElementType* BuiltInArrayList<T, N>::end() noexcept
    {
        return Data() + this->m_length;
    }

    template <class T, ssize_t N>
    constexpr const BuiltInArrayList<T, N>::ElementType* BuiltInArrayList<T, N>::end() const noexcept
    {
        return Data() + this->m_length;
    }

    template <class T, ssize_t N>
    bool BuiltInArrayList<T, N>::Append() noexcept(::std::is_nothrow_constructible_v<ElementType>) requires ::std::default_initializable<ElementType>
    {
        return Emplace();
    }

    template <class T, ssize_t N>
    bool BuiltInArrayList<T, N>::Append(
        ElementType const& value
    ) noexcept(::std::is_nothrow_copy_constructible_v<ElementType>) requires ::std::copy_constructible<ElementType>
    {
        return Emplace(value);
    }

    template <class T, ssize_t N>
    bool BuiltInArrayList<T, N>::Append(
        ElementType&& value
    ) noexcept(::std::is_nothrow_move_constructible_v<ElementType>) requires ::std::move_constructible<ElementType>
    {
        return Emplace(::std::move(value));
    }

    template <class T, ssize_t N>
    constexpr void BuiltInArrayList<T, N>::Clear() noexcept
    {
        for (ElementType& element : *this) {
            element.~ElementType();
        }
        this->m_length = 0;
    }

    template <class T, ssize_t N>
    constexpr BuiltInArrayList<T, N>::ElementType* BuiltInArrayList<T, N>::Data() noexcept
    {
        return reinterpret_cast<ElementType*>(m_arr);
    }

    template <class T, ssize_t N>
    constexpr const BuiltInArrayList<T, N>::ElementType* BuiltInArrayList<T, N>::Data() const noexcept
    {
        return reinterpret_cast<const ElementType*>(m_arr);
    }

    template <class T, ssize_t N>
    template <class... Args>
    bool BuiltInArrayList<T, N>::Emplace(
        Args&&... args
    ) noexcept(noexcept(ElementType(::std::forward<Args>(args)...)))
    {
#if KLIB_HAS_CPP23
        [[assume(0 <= this->m_length && this->m_length <= N)]];
#endif
        if (this->m_length == N) return false;

        new(Data() + this->m_length) ElementType(::std::forward<Args>(args)...);

        ++this->m_length;

        return true;
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_BUILTINARRAYLIST_H