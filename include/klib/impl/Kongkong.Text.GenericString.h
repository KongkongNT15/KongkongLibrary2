#ifndef KLIB_KONGKONG_TEXT_GENERICSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTRING_H

#include "base.h"
#include "Kongkong.Object.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 文字列クラス
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CChar TChar>
    class GenericString : public Object {
    protected:

        struct ImplType : public Object::ImplType {
        protected:
            /// <summary>
            /// 文字列の長さ
            /// </summary>
            ssize_t m_length;

            /// <summary>
            /// 文字列へのポインター
            /// </summary>
            const TChar* m_p;

            /// <summary>
            /// メンバーを初期化
            /// </summary>
            /// <param name="length">文字列の長さ</param>
            /// <param name="p">文字列へのポインター</param>
            constexpr ImplType(ssize_t length, const TChar* p) noexcept;

            KLIB_NODISCARD constexpr const TChar* begin() const noexcept;
            KLIB_NODISCARD constexpr const TChar* end() const noexcept;

        public:

            /// <summary>
            /// Cスタイル文字列に変換
            /// </summary>
            /// <returns>文字列へのポインター</returns>
            KLIB_NODISCARD constexpr const TChar* c_str() const noexcept;

            /// <summary>
            /// 指定したインデックスの文字を取得
            /// </summary>
            /// <param name="index">インデックス</param>
            /// <returns>指定したインデックスの文字</returns>
            /// <exception cref="ArgumentOutOfRangeException">indexが範囲外の時</exception>
            KLIB_NODISCARD constexpr TChar const& At(ssize_t index) const;

            /// <summary>
            /// 文字列データを取得
            /// </summary>
            /// <returns>データへのポインター</returns>
            KLIB_NODISCARD constexpr const TChar* Data() const noexcept;

            /// <summary>
            /// 文字列の長さを取得
            /// </summary>
            /// <returns>文字列の長さ</returns>
            KLIB_NODISCARD constexpr ssize_t Length() const noexcept;
        };

    public:
        KLIB_KONGKONG_OBJECT_OMAJINAI(GenericString, Object)

        GenericString(const TChar* cStr);
        GenericString(ssize_t length, const TChar* cStr);

        KLIB_NODISCARD const TChar& operator[](ssize_t index) const;

        KLIB_NODISCARD const TChar* begin() const;
        KLIB_NODISCARD const TChar* end() const;
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr GenericString<TChar>::ImplType::ImplType(ssize_t length, const TChar* p) noexcept
        : m_length(length)
        , m_p(p)
    {
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::begin() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::end() const noexcept
    {
        return m_p + m_length;
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::c_str() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::Data() const noexcept
    {
        return m_p;
    }

    template <CChar TChar>
    constexpr ssize_t GenericString<TChar>::ImplType::Length() const noexcept
    {
        return m_length;
    }

    template <CChar TChar>
    const TChar& GenericString<TChar>::operator[](ssize_t index) const
    {
        return *(this->c_str() + index);
    }

    template <CChar TChar>
    const TChar* GenericString<TChar>::begin() const
    {
        return Object::GetPointerChecked<ImplType>()->begin();
    }

    template <CChar TChar>
    const TChar* GenericString<TChar>::end() const
    {
        return Object::GetPointerChecked<ImplType>()->end();
    }
}

#include "Kongkong.ArgumentOutOfRangeException.h"

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr TChar const& GenericString<TChar>::ImplType::At(ssize_t index) const
    {
        if (index < 0 || m_length <= index) [[unlikely]] throw ArgumentOutOfRangeException(u"指定したインデックスが範囲外です");

        return m_p[index];
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRING_H