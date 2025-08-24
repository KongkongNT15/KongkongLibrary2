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



        [[nodiscard]] constexpr ElementType* begin() const noexcept;
        [[nodiscard]] constexpr ElementType* end() const noexcept;

        /// <summary>
        /// 読み取り専用Spanを取得
        /// </summary>
        [[nodiscard]] constexpr ReadOnlySpan<::std::remove_const_t<ElementType>> AsReadOnly() const noexcept;

        /// <summary>
        /// 配列へのポインターを取得
        /// </summary>
        [[nodiscard]] constexpr ElementType* Data() const noexcept;
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
    constexpr ReadOnlySpan<::std::remove_const_t<typename Span<T>::ElementType>> Span<T>::AsReadOnly() const noexcept
    {
        return ReadOnlySpan<::std::remove_const_t<typename Span<T>::ElementType>>::CreateUnsafe(
            length,
            p
        );
    }

    template <class T>
    constexpr Span<T>::ElementType* Span<T>::Data() const noexcept
    {
        return m_p;
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_SPAN_H