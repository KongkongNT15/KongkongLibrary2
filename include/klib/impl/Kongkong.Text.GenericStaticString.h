#ifndef KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H

#include "base.h"
#include "Kongkong.Text.GenericString.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 静的領域に配置される文字列
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CCharType TChar>
    class GenericStaticString : public GenericString<TChar> {
    public:
        /// <summary>
        /// 実態型
        /// </summary>
        /// <typeparam name="N">配列の長さ</typeparam>
        struct ImplType : public GenericString<TChar>::ImplType {
        private:

        public:

            template <ssize_t N>
            ImplType(const TChar(&arr)[N]) noexcept
                : GenericString<TChar>::ImplType(N - 1, arr)
            {
                Object::ImplType::SetAsNonDeleteObject();
            }
        };

        KLIB_KONGKONG_OBJECT_OMAJINAI(GenericStaticString, GenericString<TChar>);

        explicit constexpr GenericStaticString(ImplType& value) noexcept;
    };
}

namespace klib::Kongkong::Text
{
    template <CCharType TChar>
    constexpr GenericStaticString<TChar>::GenericStaticString(ImplType& value) noexcept
        : GenericString<TChar>(nullptr)
    {
        Object::SetInstanceUnsafe(&value);
    }
}

#endif //! KLIB_KONGKONG_TEXT_GENERICSTATICSTRING_H