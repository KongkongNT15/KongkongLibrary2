#ifndef KLIB_KONGKONG_TEXT_GENERICSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTRING_H

#include "base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Text.GenericFastStringBase.h"

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
            /// 文字列オブジェクト
            /// </summary>
            GenericFastStringBase<TChar>* m_pStr;

            /// <summary>
            /// メンバーを初期化
            /// </summary>
            /// <param name="pStr">文字列オブジェクト</param>
            constexpr ImplType(
                GenericFastStringBase<TChar>* pStr
            ) noexcept;

            [[nodiscard]] constexpr const TChar* begin() const noexcept;
            [[nodiscard]] constexpr const TChar* end() const noexcept;

        public:

            /// <summary>
            /// Cスタイル文字列に変換
            /// </summary>
            /// <returns>文字列へのポインター</returns>
            [[nodiscard]] constexpr const TChar* c_str() const noexcept;

            /// <summary>
            /// 指定したインデックスの文字を取得
            /// </summary>
            /// <param name="index">インデックス</param>
            /// <returns>指定したインデックスの文字</returns>
            /// <exception cref="ArgumentOutOfRangeException">indexが範囲外の時</exception>
            [[nodiscard]] constexpr TChar const& At(
                ssize_t index
            ) const;

            /// <summary>
            /// 文字列データを取得
            /// </summary>
            /// <returns>データへのポインター</returns>
            [[nodiscard]] constexpr const TChar* Data() const noexcept;

            /// <summary>
            /// 文字列の長さを取得
            /// </summary>
            /// <returns>文字列の長さ</returns>
            [[nodiscard]] constexpr ssize_t Length() const noexcept;
        };

    public:
        KLIB_KONGKONG_OBJECT_OMAJINAI(GenericString, Object)

        GenericString(
            const TChar* cStr
        );

        GenericString(
            ssize_t length,
            const TChar* cStr
        );

        [[nodiscard]] const TChar& operator[](
            ssize_t index
        ) const;

        [[nodiscard]] const TChar* begin() const;
        [[nodiscard]] const TChar* end() const;
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr GenericString<TChar>::ImplType::ImplType(
        GenericFastStringBase<TChar>* pStr
    ) noexcept
        : m_pStr(pStr)
    {
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::begin() const noexcept
    {
        return m_pStr->begin();
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::end() const noexcept
    {
        return m_pStr->end();
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::c_str() const noexcept
    {
        return m_pStr->Data();
    }

    template <CChar TChar>
    constexpr TChar const& GenericString<TChar>::ImplType::At(
        ssize_t index
    ) const
    {
        return m_pStr->At(index);
    }

    template <CChar TChar>
    constexpr const TChar* GenericString<TChar>::ImplType::Data() const noexcept
    {
        return m_pStr->Data();
    }

    template <CChar TChar>
    constexpr ssize_t GenericString<TChar>::ImplType::Length() const noexcept
    {
        return m_pStr->Length();
    }

    template <CChar TChar>
    const TChar& GenericString<TChar>::operator[](
        ssize_t index
    ) const
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

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRING_H