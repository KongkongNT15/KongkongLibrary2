#ifndef KLIB_KONGKONG_CONTAINTERS_SPAN_H
#define KLIB_KONGKONG_CONTAINTERS_SPAN_H

#include "base.h"
#include "Kongkong.NonType.h"
#include "Kongkong.ValueType.h"

namespace klib::Kongkong::Containers
{
    /// <summary>
    /// 配列ビュー
    /// </summary>
    /// <typeparam name="T">要素型</typeparam>
    template <class T>
    struct Span final : public ValueType {
    public:
        /// <summary>
        /// 要素の型
        /// </summary>
        using ElementType = typename ::std::remove_reference_t<T>;
    private:
        /// <summary>
        /// 要素数
        /// </summary>
        ssize_t m_length;

        /// <summary>
        /// 配列へのポインター
        /// </summary>
        ElementType* m_p;

        /// <summary>
        /// 安全性を確認せずに構築
        /// </summary>
        /// <param name="length">要素数</param>
        /// <param name="p">配列へのポインター</param>
        /// <param name="nonType">使わないよ</param>
        explicit constexpr Span(
            ssize_t length,
            ElementType* p,
            NonType nonType
        ) noexcept;
    public:

        /// <summary>
        /// IndexOf()で要素が見つからなかった時の戻り値
        /// </summary>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;

        /// <summary>
        /// ふぁ！？っく
        /// </summary>
        static constexpr Span CreateUnsafe(
            ssize_t,
            ::std::nullptr_t
        ) = delete;

        /// <summary>
        /// 安全性を確認せずに構築
        /// </summary>
        /// <param name="length">要素数</param>
        /// <param name="p">配列へのポインター</param>
        /// <returns>構築されたオブジェクト</returns>
        [[nodiscard]] static constexpr Span CreateUnsafe(
            ssize_t length,
            ElementType* p
        ) noexcept;

        /// <summary>
        /// 要素を取得
        /// </summary>
        /// <param name="index">要素番号</param>
        /// <returns>要素の参照</returns>
        [[nodiscard]] constexpr ElementType& operator[](
            ssize_t index
        ) noexcept;

        [[nodiscard]] constexpr ElementType* begin() const noexcept;
        [[nodiscard]] constexpr ElementType* end() const noexcept;

        /// <summary>
        /// 読み取り専用Spanを取得
        /// </summary>
        [[nodiscard]] constexpr ReadOnlySpan<::std::remove_const_t<ElementType>> AsReadOnly() const noexcept;

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
        [[nodiscard]] constexpr ElementType* Data() const noexcept;

        /// <summary>
        /// 配列の最後の要素が指定した値と一致するかを判定
        /// </summary>
        /// <param name="value">指定する値</param>
        /// <returns>判定結果</returns>
        [[nodiscard]] constexpr bool EndsWith(
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
    template <class T>
    constexpr Span<T>::Span(
        ssize_t length,
        ElementType* p,
        NonType
    ) noexcept
        : m_length(length)
        , m_p(p)
    {
    }

    template <class T>
    consteval ssize_t Span<T>::NotFound() noexcept
    {
        return ContainerHelper::NotFound();
    }

    template <class T>
    constexpr Span<T> Span<T>::CreateUnsafe(
        ssize_t length,
        ElementType* p
    ) noexcept
    {
        return Span<T>(
            length,
            p,
            {}
        );
    }

    template <class T>
    constexpr Span<T>::ElementType& Span<T>::operator[](
        ssize_t index
        ) noexcept
    {
        return m_p[index];
    }

    template <class T>
    constexpr Span<T>::ElementType* Span<T>::begin() const noexcept
    {
        return m_p;
    }

    template <class T>
    constexpr Span<T>::ElementType* Span<T>::end() const noexcept
    {
        return m_p + m_length;
    }

    template <class T>
    constexpr ReadOnlySpan<::std::remove_const_t<typename Span<T>::ElementType>>
    Span<T>::AsReadOnly() const noexcept
    {
        return ReadOnlySpan<::std::remove_const_t<typename Span<T>::ElementType>>::CreateUnsafe(
            m_length,
            m_p
        );
    }



    template <class T>
    constexpr bool Span<T>::Contains(
        ElementType const& value
    ) const noexcept
    {
        return ContainerHelper::ContainsUnsafe(
            m_length,
            m_p,
            value
        );
    }

    template <class T>
    constexpr Span<T>::ElementType* Span<T>::Data() const noexcept
    {
        return m_p;
    }

    template <class T>
    constexpr bool Span<T>::EndsWith(
        ElementType const& value
    ) const noexcept
    {
        return ContainerHelper::EndsWithUnsafe(
            m_length,
            m_p,
            value
        );
    }

    template <class T>
    constexpr bool Span<T>::StartsWith(
        ElementType const& value
    ) const noexcept
    {
        return ContainerHelper::StartsWithUnsafe(
            m_length,
            m_p,
            value
        );
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_SPAN_H