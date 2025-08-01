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
    template <CCharType TChar>
    class GenericString : public Object {
    protected:

        struct ImplType : public Object::ImplType {
        protected:
            ssize_t m_length;
            const TChar* m_p;

            /// <summary>
            /// メンバーを初期化
            /// </summary>
            /// <param name="length">文字列の長さ</param>
            /// <param name="p">文字列へのポインター</param>
            constexpr ImplType(ssize_t length, const TChar* p) noexcept;

        public:

            /// <summary>
            /// Cスタイル文字列に変換
            /// </summary>
            /// <returns>文字列へのポインター</returns>
            [[nodiscard]] constexpr const TChar* c_str() const noexcept;

            /// <summary>
            /// 文字列の長さを取得
            /// </summary>
            /// <returns>文字列の長さ</returns>
            [[nodiscard]] constexpr ssize_t Length() const noexcept;
        };

    public:
        KLIB_KONGKONG_OBJECT_OMAJINAI(GenericString, Object)
    };
}

namespace klib::Kongkong::Text
{
    template <CCharType TChar>
    constexpr GenericString<TChar>::ImplType::ImplType(ssize_t length, const TChar* p) noexcept
        : m_length(length)
        , m_p(p)
    {
    }

    template <CCharType TChar>
    constexpr ssize_t GenericString<TChar>::ImplType::Length() const noexcept
    {
        return m_length;
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRING_H