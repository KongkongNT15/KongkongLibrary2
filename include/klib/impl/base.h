#ifndef KLIB_BASE_H
#define KLIB_BASE_H

#include <stdint.h>
#include <concepts>
#include <compare>
#include <type_traits>

#if __has_include(<Windows.h>)
    #define KLIB_ENV_WINDOWS 1

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

// インスタンス化できないようにする
#define KLIB_STATIC_CLASS(className) \
    className() = delete; \
    className(className const&) = delete; \
    className(className&&) = delete; \
    ~className() = delete; \
    className& operator=(className const&) = delete; \
    className& operator=(className&&) = delete

#define KLIB_INTERFACE struct

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
    template <class T>
    concept CCharType =
        ::std::same_as<T, char> ||
        ::std::same_as<T, wchar_t> ||
        ::std::same_as<T, char8_t> ||
        ::std::same_as<T, char16_t> ||
        ::std::same_as<T, char32_t>;

    class GC;
    class Interface;
    class Object;

    struct Exception;
    struct InvalidCastException;
    struct MemoryAllocationException;
    struct NullPointerException;
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
}

namespace klib::Kongkong::IO
{

}

/// <summary>
/// 数値関連
/// </summary>
namespace klib::Kongkong::Numerics
{

}

/// <summary>
/// 文字列関連
/// </summary>
namespace klib::Kongkong::Text
{
    template <CCharType TChar, ssize_t N>
    class GenericBuiltInMutableString;

    template <CCharType TChar>
    class GenericString;

    template <CCharType TChar>
    class GenericFastMutableString;

    template <CCharType TChar>
    class GenericHeapString;

    template <CCharType TChar>
    class GenericStaticString;
}

namespace klib::Kongkong::Threading
{

}

// エイリアス
namespace klib::Kongkong
{
    using String = Text::GenericString<char16_t>;
}

namespace klib::Kongkong::Text
{
    using String = GenericString<char16_t>;
    using CharString = GenericString<char>;
    using WCharString = GenericString<wchar_t>;
    using Utf8String = GenericString<char8_t>;
    using Utf16String = GenericString<char16_t>;
    using Utf32String = GenericString<char32_t>;

    using HeapString = GenericHeapString<char16_t>;
    using HeapCharString = GenericHeapString<char>;
    using HeapWCharString = GenericHeapString<wchar_t>;
    using HeapUtf8String = GenericHeapString<char8_t>;
    using HeapUtf16String = GenericHeapString<char16_t>;
    using HeapUtf32String = GenericHeapString<char32_t>;

    using StaticString = GenericStaticString<char16_t>;
    using StaticCharString = GenericStaticString<char>;
    using StaticWCharString = GenericStaticString<wchar_t>;
    using StaticUtf8String = GenericStaticString<char8_t>;
    using StaticUtf16String = GenericStaticString<char16_t>;
    using StaticUtf32String = GenericStaticString<char32_t>;
}

#endif //!KLIB_BASE_H