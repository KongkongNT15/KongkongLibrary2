#ifndef KONGKONG_WIN32_WINERROR_H
#define KONGKONG_WIN32_WINERROR_H

#include "base.h"

namespace klib::Kongkong::Win32
{
    /// <summary>
    /// Win32APIのエラー
    /// </summary>
    class WinError final {
    public:

        KLIB_STATIC_CLASS(WinError);

        /// <summary>
        /// エラーコードから例外をスロー
        /// </summary>
        /// <param name="errorCode">エラーコード</param>
        static void Throw(
            ::DWORD errorCode
        );

        /// <summary>
        /// エラーコードから例外をスロー
        /// </summary>
        /// <param name="errorCode">エラーコード</param>
        static void Throw(
            ::HRESULT errorCode
        );

        /// <summary>
        /// エラーコードからエラーメッセージを取得
        /// </summary>
        /// <param name="errorCode">エラーコード</param>
        /// <returns>エラーメッセージ</returns>
        /// <exception cref="MemoryAllocationException">メモリ確保に失敗したとき</exception>
        [[nodiscard]] static String ToString(
            ::DWORD errorCode
        );

        /// <summary>
        /// エラーコードからエラーメッセージを取得
        /// </summary>
        /// <param name="errorCode">エラーコード</param>
        /// <returns>エラーメッセージ</returns>
        /// <exception cref="MemoryAllocationException">メモリ確保に失敗したとき</exception>
        [[nodiscard]] static String ToString(
            ::HRESULT errorCode
        );
    };
}

#endif //!KONGKONG_WIN32_WINERROR_H