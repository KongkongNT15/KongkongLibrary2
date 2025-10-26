#ifndef KLIB_KONGKONG_INVALIDCASTEXCEPTION_H
#define KLIB_KONGKONG_INVALIDCASTEXCEPTION_H

#include "base.h"
#include "Kongkong.Exception.h"
#include "Kongkong.Text.GenericStaticString.h"

namespace klib::Kongkong
{
    /// <summary>
    /// キャスト失敗時の例外
    /// </summary>
    struct InvalidCastException : public Exception {
    private:

        static Text::StaticString<12>::ImplType s_message;

    public:
        InvalidCastException() noexcept;
        using Exception::Exception;
    };
}

namespace klib::Kongkong
{
    inline InvalidCastException::InvalidCastException() noexcept
        : Exception(Text::StaticString<12>(s_message))
    {
    }
}

#endif //!KLIB_KONGKONG_INVALIDCASTEXCEPTION_H