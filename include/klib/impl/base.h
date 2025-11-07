#ifndef KLIB_BASE_H
#define KLIB_BASE_H

#include <stdint.h>
#include <concepts>
#include <compare>
#include <new>
#include <type_traits>

#if __has_include(<Windows.h>)
    #define KLIB_ENV_WINDOWS 1
    #include <Windows.h>

    #if __cplusplus == 199711L
        #define KLIB_COMPILER_MSVC 1
        #define KLIB_CPP_LANG_VERSION _MSVC_LANG

        #if defined(_M_ARM64)
            #define KLIB_ENV_ARM64 1
        #elif defined(_M_X64)
            #define KLIB_ENV_X64 1
        #endif
    #else
        #define KLIB_COMPILER_MSVC 0
        #define KLIB_CPP_LANG_VERSION __cplusplus
    #endif

    #if defined(__MINGW32__) || defined(__MINGW64__)
        #define KLIB_COMPILER_MINGW 1
        #if defined(__aarch64__)
            #define KLIB_ENV_ARM64 1
        #elif defined(__x86_64__)
            #define KLIB_ENV_X64 1
        #endif
    #endif
#endif

#if __has_include(<unistd.h>) && !defined(KLIB_ENV_WINDOWS)
    #define KLIB_ENV_UNIX 1

    #include <unistd.h>
#endif

#ifdef __APPLE__
    #define KLIB_ENV_APPLE 1

    #if defined(__aarch64__) || defined(__arm64__)
        #define KLIB_ENV_ARM64 1
    #else
        #define KLIB_ENV_X64 1
    #endif
#endif

#ifdef __linux__
    #define KLIB_ENV_LINUX 1

    #ifdef __aarch64__
        #define KLIB_ENV_ARM64 1
    #endif

    #ifdef __x86_64__
        #define KLIB_ENV_X64 1
    #endif
#endif

#ifndef KLIB_CPP_LANG_VERSION
    #define KLIB_CPP_LANG_VERSION __cplusplus
#endif

#define KLIB_CPP11 201103L
#define KLIB_CPP14 201402L
#define KLIB_CPP17 201703L
#define KLIB_CPP20 202002L
#define KLIB_CPP23 202302L

#if KLIB_CPP_LANG_VERSION >= KLIB_CPP11
    #define KLIB_HAS_CPP11 1
#else
    #define KLIB_HAS_CPP11 0
#endif

#if KLIB_CPP_LANG_VERSION >= KLIB_CPP14
    #define KLIB_HAS_CPP14 1
#else
    #define KLIB_HAS_CPP14 0
#endif

#if KLIB_CPP_LANG_VERSION >= KLIB_CPP17
    #define KLIB_HAS_CPP17 1
#else
    #define KLIB_HAS_CPP17 0
#endif

#if KLIB_CPP_LANG_VERSION >= KLIB_CPP20
    #define KLIB_HAS_CPP20 1
#else
    #define KLIB_HAS_CPP20 0
#endif

#if KLIB_CPP_LANG_VERSION >= KLIB_CPP23
    #define KLIB_HAS_CPP23 1
#else
    #define KLIB_HAS_CPP23 0
#endif

#ifndef KLIB_ENV_WINDOWS
    #define KLIB_ENV_WINDOWS 0
#endif

#ifndef KLIB_ENV_UNIX
    #define KLIB_ENV_UNIX 0
#endif

#ifndef KLIB_COMPILER_MSVC
    #define KLIB_COMPILER_MSVC 0
#endif

#ifndef KLIB_COMPILER_MINGW
    #define KLIB_COMPILER_MINGW 0
#endif

#ifndef KLIB_ENV_APPLE
    #define KLIB_ENV_APPLE 0
#endif

#ifndef KLIB_ENV_LINUX
    #define KLIB_ENV_LINUX 0
#endif

#ifndef KLIB_ENV_ARM64
    #define KLIB_ENV_ARM64 0
#endif

#ifndef KLIB_ENV_X64
    #define KLIB_ENV_X64 0
#endif

#if KLIB_ENV_UNIX || KLIB_ENV_WINDOWS
    #define KLIB_ENV_OTHER 0
#else
    #define KLIB_ENV_OTHER 1
#endif

#if KLIB_HAS_CPP20
    #define KLIB_LIKELY [[likely]]
    #define KLIB_UNLIKELY [[unlikely]]
#else
    #define KLIB_LIKELY 
    #define KLIB_UNLIKELY
#endif

#if KLIB_HAS_CPP20
    #define KLIB_CPP20_CONSTEXPR constexpr
#else
    #define KLIB_CPP20_CONSTEXPR
#endif

#if KLIB_HAS_CPP23
    #define KLIB_CPP23_CONSTEXPR constexpr
    #define KLIB_CPP23_CONSTEXPR_OR_INLINE constexpr
#else
    #define KLIB_CPP23_CONSTEXPR
    #define KLIB_CPP23_CONSTEXPR_OR_INLINE inline
#endif

// インスタンス化できないようにする
#define KLIB_STATIC_CLASS(className) \
    className() = delete; \
    className(className const&) = delete; \
    className(className&&) = delete; \
    ~className() = delete; \
    className& operator=(className const&) = delete; \
    className& operator=(className&&) = delete

#define KLIB_INTERFACE struct

#define KLIB_NEW new(::std::nothrow)

// msvcではssize_tは定義されないので追加
#if KLIB_COMPILER_MSVC
    #ifdef _WIN64
        /// <summary>
        /// ポインターと同じ長さの整数型
        /// </summary>
        using ssize_t = int64_t;
    #else
        /// <summary>
        /// ポインターと同じ長さの整数型
        /// </summary>
        using ssize_t = int32_t;
    #endif
#endif

/// <summary>
/// 既定の名前空間
/// </summary>
namespace klib
{
}

/// <summary>
/// 基本クラスたち
/// </summary>
namespace klib::Kongkong
{

    class GC;
    class Interface;
    class Object;

    struct ArgumentException;
    struct ArgumentNullException;
    struct ArgumentOutOfRangeException;
    struct ErrorCode;
    struct Exception;
    class HandleType;
    struct InvalidCastException;
    struct MemoryAllocationException;
    struct NonType;
    struct NullPointerException;
    class PointerType;
    struct ValueType;
}

/// <summary>
/// コマンドライン
/// </summary>
namespace klib::Kongkong::Cli
{
    class CliOption;
}

/// <summary>
/// コンテナ型
/// </summary>
namespace klib::Kongkong::Containers
{
    template <class T>
    KLIB_INTERFACE IIterable;

    template <class T>
    KLIB_INTERFACE IReadOnlyIterable;

    class ContainerHelper;

    template <class T, ssize_t N>
    struct BuiltInArray;

    template <class T, ssize_t N>
    struct BuiltInArrayList;

    template <class T>
    struct s_arrayBase;

    struct s_containerBase;

    template <class T>
    struct Span;

    template <class T>
    struct Span2;

    template <class T>
    struct Span3;
}

namespace klib::Kongkong::IO
{

}

namespace klib::Kongkong::Memory
{
    struct GCMemoryBlock;
    class GCPointer;
    struct MemoryBlock;
}

/// <summary>
/// 数値関連
/// </summary>
namespace klib::Kongkong::Numerics
{
    /// <summary>
    /// 浮動小数点数
    /// </summary>
    template <class T>
    concept CFloat = ::std::floating_point<T>;

    /// <summary>
    /// 数値型
    /// </summary>
    template <class T>
    concept CNumber =
        (::std::integral<T> || ::std::floating_point<T>) &&
        (::std::same_as<T, bool> == false);

    /// <summary>
    /// 符号付き数値型
    /// </summary>
    template <class T>
    concept CSignedNumber =
        (::std::signed_integral<T> || ::std::floating_point<T>);

    /// <summary>
    /// 符号なし数値型
    /// </summary>
    template <class T>
    concept CUnsignedNumber =
        ::std::unsigned_integral<T> &&
        ::std::same_as<T, bool> == false;

    class Math;

    template <class T = void>
    struct Number;

    template <class T>
    struct NumberParseResult;
}

/// <summary>
/// 文字列関連
/// </summary>
namespace klib::Kongkong::Text
{
    template <class T>
    concept CChar =
        ::std::same_as<T, char> ||
        ::std::same_as<T, wchar_t> ||
        ::std::same_as<T, char8_t> ||
        ::std::same_as<T, char16_t> ||
        ::std::same_as<T, char32_t>;

    template <CChar TChar>
    struct GenericFastString;

    template <CChar TChar>
    struct GenericFastStringBase;

    template <CChar TChar, ssize_t N>
    struct GenericStaticFastString;

    template <CChar TChar, ssize_t N>
    struct GenericStaticMutableString;

    template <CChar TChar>
    class GenericString;

    template <CChar TChar>
    struct GenericStringMemory;

    template <CChar TChar>
    class GenericFastMutableString;

    template <CChar TChar>
    class GenericHeapString;

    template <CChar TChar, ssize_t N>
    class GenericStaticString;

    class StaticStringHelper;
    class StringHelper;

    template <CChar TChar>
    struct GenericStringView;

    template <CChar TChar, ssize_t N>
    struct StaticStringHelperResult;
}

namespace klib::Kongkong::Threading
{
    class Mutex;
}

/// <summary>
/// Win32APIのラッパー
/// </summary>
namespace klib::Kongkong::Win32
{
    class Handle;
    class WinError;
}

// エイリアス
namespace klib::Kongkong
{
    using String = Text::GenericString<char16_t>;
}

namespace klib::Kongkong::Containers
{
    template <class T>
    using ReadOnlySpan = Span<T>;

    template <class T>
    using ReadOnlySpan2 = Span2<T>;

    template <class T>
    using ReadOnlySpan3 = Span3<T>;
}

namespace klib::Kongkong::Text
{
    using String = GenericString<char16_t>;
    using CharString = GenericString<char>;
    using WCharString = GenericString<wchar_t>;
    using Utf8String = GenericString<char8_t>;
    using Utf16String = GenericString<char16_t>;
    using Utf32String = GenericString<char32_t>;

    using StringMemory = GenericStringMemory<char16_t>;
    using CharStringMemory = GenericStringMemory<char>;
    using WCharStringMemory = GenericStringMemory<wchar_t>;
    using Utf8StringMemory = GenericStringMemory<char8_t>;
    using Utf16StringMemory = GenericStringMemory<char16_t>;
    using Utf32StringMemory = GenericStringMemory<char32_t>;

    using FastString = GenericFastString<char16_t>;
    using FastCharString = GenericFastString<char>;
    using FastWCharString = GenericFastString<wchar_t>;
    using FastUtf8String = GenericFastString<char8_t>;
    using FastUtf16String = GenericFastString<char16_t>;
    using FastUtf32String = GenericFastString<char32_t>;

    using FastStringBase = GenericFastStringBase<char16_t>;
    using FastCharStringBase = GenericFastStringBase<char>;
    using FastWCharStringBase = GenericFastStringBase<wchar_t>;
    using FastUtf8StringBase = GenericFastStringBase<char8_t>;
    using FastUtf16StringBase = GenericFastStringBase<char16_t>;
    using FastUtf32StringBase = GenericFastStringBase<char32_t>;

    using HeapString = GenericHeapString<char16_t>;
    using HeapCharString = GenericHeapString<char>;
    using HeapWCharString = GenericHeapString<wchar_t>;
    using HeapUtf8String = GenericHeapString<char8_t>;
    using HeapUtf16String = GenericHeapString<char16_t>;
    using HeapUtf32String = GenericHeapString<char32_t>;

    template <ssize_t N>
    using StaticString = GenericStaticString<char16_t, N>;

    template <ssize_t N>
    using StaticCharString = GenericStaticString<char, N>;

    template <ssize_t N>
    using StaticWCharString = GenericStaticString<wchar_t, N>;

    template <ssize_t N>
    using StaticUtf8String = GenericStaticString<char8_t, N>;

    template <ssize_t N>
    using StaticUtf16String = GenericStaticString<char16_t, N>;

    template <ssize_t N>
    using StaticUtf32String = GenericStaticString<char32_t, N>;

    template <ssize_t N = 0>
    using StaticFastString = GenericStaticFastString<char16_t, N>;

    template <ssize_t N>
    using StaticFastCharString = GenericStaticFastString<char, N>;

    template <ssize_t N>
    using StaticFastWCharString = GenericStaticFastString<wchar_t, N>;

    template <ssize_t N>
    using StaticFastUtf8String = GenericStaticFastString<char8_t, N>;

    template <ssize_t N>
    using StaticFastUtf16String = GenericStaticFastString<char16_t, N>;

    template <ssize_t N>
    using StaticFastUtf32String = GenericStaticFastString<char32_t, N>;

    template <ssize_t N>
    using StaticMutableString = GenericStaticMutableString<char16_t, N>;

    template <ssize_t N>
    using StaticMutableCharString = GenericStaticMutableString<char, N>;

    template <ssize_t N>
    using StaticMutableWCharString = GenericStaticMutableString<wchar_t, N>;

    template <ssize_t N>
    using StaticMutableUtf8String = GenericStaticMutableString<char8_t, N>;

    template <ssize_t N>
    using StaticMutableUtf16String = GenericStaticMutableString<char16_t, N>;

    template <ssize_t N>
    using StaticMutableUtf32String = GenericStaticMutableString<char32_t, N>;

    using StringView = GenericStringView<char16_t>;
    using CharStringView = GenericStringView<char>;
    using WCharStringView = GenericStringView<wchar_t>;
    using Utf8StringView = GenericStringView<char8_t>;
    using Utf16StringView = GenericStringView<char16_t>;
    using Utf32StringView = GenericStringView<char32_t>;
}

#endif //!KLIB_BASE_H