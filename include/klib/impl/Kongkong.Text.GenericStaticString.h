#ifndef KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H

#include "base.h"
#include "Kongkong.Text.GenericString.h"
#include "Kongkong.Text.GenericStringView.h"
#include "Kongkong.Text.GenericStaticFastString.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 静的領域に配置される文字列
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CChar TChar, ssize_t N>
    class GenericStaticString : public GenericString<TChar> {
    public:
        /// <summary>
        /// 実態型
        /// </summary>
        /// <typeparam name="N">配列の長さ</typeparam>
        struct ImplType : public GenericString<TChar>::ImplType {
        private:

            GenericStaticFastString<TChar, N> m_string;
            GenericStringView<TChar> m_view;

        public:

            ImplType(const TChar(&arr)[N]) noexcept
                : GenericString<TChar>::ImplType(
                    &m_view
                )
                , m_string(arr)
                , m_view(
                    GenericStringView<TChar>::CreateUnsafe(
                        m_string.Length(),
                        m_string.Data()
                    )
                )
            {
                Object::ImplType::SetAsNonDeleteObject();
            }
        };

        KLIB_KONGKONG_OBJECT_OMAJINAI(GenericStaticString, GenericString<TChar>);

        explicit constexpr GenericStaticString(
            ImplType& value
        ) noexcept;
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar, ssize_t N>
    constexpr GenericStaticString<TChar, N>::GenericStaticString(
        ImplType& value
    ) noexcept
        : GenericString<TChar>(nullptr)
    {
        Object::SetInstanceUnsafe(&value);
    }
}

#endif //! KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H