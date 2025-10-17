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
        /// 末尾に要素をデフォルト構築
        /// </summary>
        /// <returns>要素を追加できたかどうか</returns>
        bool Append()
        noexcept(::std::is_nothrow_constructible_v<ElementType>)
        requires ::std::default_initializable<ElementType>;

        /// <summary>
        /// 末尾に要素をコピー構築
        /// </summary>
        /// <param name="value">追加する要素</param>
        /// <returns>要素を追加できたかどうか</returns>
        bool Append(
            ElementType const& value
        )
        noexcept(::std::is_nothrow_copy_constructible_v<ElementType>)
        requires ::std::copy_constructible<ElementType>;

        /// <summary>
        /// 末尾に要素をムーブ構築
        /// </summary>
        /// <param name="value">追加する要素</param>
        /// <returns>要素を追加できたかどうか</returns>
        bool Append(
            ElementType&& value
        )
        noexcept(::std::is_nothrow_move_constructible_v<ElementType>)
        requires ::std::move_constructible<ElementType>;

        /// <summary>
        /// 要素をすべて破棄
        /// </summary>
        constexpr void Clear() noexcept;

        /// <summary>
        /// 指定した値が配列に含まれるかを判定
        /// </summary>
        /// <param name="value">指定する値</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool Contains(
            ElementType const& value
        ) const noexcept;

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

        /// <summary>
        /// 配列の最後の要素が指定した値と一致するかを判定
        /// </summary>
        /// <param name="value">指定する値</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool EndsWith(
            ElementType const& value
        ) const noexcept;

        /// <summary>
        /// 指定した要素の要素番号を取得
        /// </summary>
        /// <param name="value">要素</param>
        /// <returns>指定した要素がある要素番号 見つからない場合はNotFound()</returns>
        [[nodiscard]] constexpr ssize_t IndexOf(
            ElementType const& value
        ) const noexcept;

        /// <summary>
        /// 配列の初めの要素が指定した値と一致するかを判定
        /// </summary>
        /// <param name="value">指定する値</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool StartsWith(
            ElementType const& value
        ) const noexcept;

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
    constexpr typename BuiltInArrayList<T, N>::ElementType&
    BuiltInArrayList<T, N>::operator[](
        ssize_t index
    ) noexcept
    {
        return m_arr[index];
    }

    template <class T, ssize_t N>
    constexpr typename BuiltInArrayList<T, N>::ElementType const&
    BuiltInArrayList<T, N>::operator[](
        ssize_t index
    ) const noexcept
    {
        return m_arr[index];
    }

    template <class T, ssize_t N>
    constexpr typename BuiltInArrayList<T, N>::ElementType*
    BuiltInArrayList<T, N>::begin() noexcept
    {
        return Data();
    }

    template <class T, ssize_t N>
    constexpr const typename BuiltInArrayList<T, N>::ElementType*
    BuiltInArrayList<T, N>::begin() const noexcept
    {
        return Data();
    }

    template <class T, ssize_t N>
    constexpr typename BuiltInArrayList<T, N>::ElementType*
    BuiltInArrayList<T, N>::end() noexcept
    {
        return Data() + this->m_length;
    }

    template <class T, ssize_t N>
    constexpr const typename BuiltInArrayList<T, N>::ElementType*
    BuiltInArrayList<T, N>::end() const noexcept
    {
        return Data() + this->m_length;
    }

    template <class T, ssize_t N>
    bool BuiltInArrayList<T, N>::Append()
    noexcept(::std::is_nothrow_constructible_v<ElementType>)
    requires ::std::default_initializable<ElementType>
    {
        return Emplace();
    }

    template <class T, ssize_t N>
    bool BuiltInArrayList<T, N>::Append(
        ElementType const& value
    )
    noexcept(::std::is_nothrow_copy_constructible_v<ElementType>)
    requires ::std::copy_constructible<ElementType>
    {
        return Emplace(value);
    }

    template <class T, ssize_t N>
    bool BuiltInArrayList<T, N>::Append(
        ElementType&& value
    )
    noexcept(::std::is_nothrow_move_constructible_v<ElementType>)
    requires ::std::move_constructible<ElementType>
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
    constexpr bool BuiltInArrayList<T, N>::Contains(
        ElementType const& value
    ) const noexcept
    {
        return ContainerHelper::ContainsUnsafe(
            this->m_length,
            Data(),
            value
        );
    }

    template <class T, ssize_t N>
    constexpr typename BuiltInArrayList<T, N>::ElementType*
    BuiltInArrayList<T, N>::Data() noexcept
    {
        return reinterpret_cast<ElementType*>(m_arr);
    }

    template <class T, ssize_t N>
    constexpr const typename BuiltInArrayList<T, N>::ElementType*
    BuiltInArrayList<T, N>::Data() const noexcept
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

    template <class T, ssize_t N>
    constexpr bool BuiltInArrayList<T, N>::EndsWith(
        ElementType const& value
    ) const noexcept
    {
        return ContainerHelper::EndsWithUnsafe(
            this->m_length,
            Data(),
            value
        );
    }

    template <class T, ssize_t N>
    constexpr bool BuiltInArrayList<T, N>::StartsWith(
        ElementType const& value
    ) const noexcept
    {
        return ContainerHelper::StartsWithUnsafe(
            this->m_length,
            Data(),
            value
        );
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_BUILTINARRAYLIST_H