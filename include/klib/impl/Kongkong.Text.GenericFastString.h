#ifndef KLIB_KONGKONG_TEXT_GENERICFASTSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICFASTSTRING_H

#include "base.h"
#include "Kongkong.NonType.h"
#include "Kongkong.Text.GenericFastStringBase.h"
#include "Kongkong.Text.GenericStringMemory.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// ヒープに確保される文字列
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CChar TChar>
    struct GenericFastString : public GenericFastStringBase<TChar> {
    public:
        /// <summary>
        /// 基底クラス
        /// </summary>
        using Base = typename GenericFastStringBase<TChar>;

        /// <summary>
        /// 要素型
        /// </summary>
        using ElementType = typename Base::ElementType;
    private:
        /// <summary>
        /// 安全性を確認せずに作成
        /// </summary>
        /// <param name="length">文字列の長さ</param>
        /// <param name="p">コピー元の文字列へのポインター</param>
        /// <param name="nonType">使わないパラメータ</param>
        /// <exception cref="MemoryAllocationException">メモリを確保できなかった時</exception>
        explicit GenericFastString(
            ssize_t length,
            const ElementType* p,
            NonType nonType
        );
    public:

        /// <summary>
        /// 文字列を連結
        /// </summary>
        /// <param name="left">連結する文字列</param>
        /// <param name="right">連結する文字列</param>
        /// <returns>連結された文字列</returns>
        /// <exception cref="MemoryAllocationException">メモリを確保できなかった時</exception>
        [[nodiscard]] static GenericFastString Concat(
            GenericFastStringBase<TChar> const& left,
            GenericFastStringBase<TChar> const& right
        );

        /// <summary>
        /// 文字列を連結
        /// </summary>
        /// <param name="str1">連結する文字列</param>
        /// <param name="str2">連結する文字列</param>
        /// <param name="str3">連結する文字列</param>
        /// <returns>連結された文字列</returns>
        /// <exception cref="MemoryAllocationException">メモリを確保できなかった時</exception>
        [[nodiscard]] static GenericFastString Concat(
            GenericFastStringBase<TChar> const& str1,
            GenericFastStringBase<TChar> const& str2,
            GenericFastStringBase<TChar> const& str3
        );

        /// <summary>
        /// 文字列リテラルから作成
        /// </summary>
        /// <typeparam name="N">文字配列の要素数</typeparam>
        /// <param name="arr">文字列リテラル</param>
        /// <returns>構築されたオブジェクト</returns>
        /// <exception cref="MemoryAllocationException">メモリを確保できなかった時</exception>
        template <ssize_t N>
        [[nodiscard]] static GenericFastString FromLiteral(
            const ElementType(&arr)[N]
        );

        /// <summary>
        /// メモリから作成
        /// </summary>
        /// <param name="memory">メモリ領域</param>
        /// <returns>構築されたオブジェクト</returns>
        [[nodiscard]] static constexpr GenericFastString FromMemoryUnsafe(
            GenericStringMemory<TChar> const& memory
        ) noexcept;

        constexpr GenericFastString() noexcept;

        /// <summary>
        /// 文字列をコピー
        /// </summary>
        /// <param name="right">コピー元の値</param>
        /// <exception cref="MemoryAllocationException">メモリを確保できなかった時</exception>
        GenericFastString(
            Base const& right
        );

        /// <summary>
        /// 文字列をコピー
        /// </summary>
        /// <param name="right">コピー元の値</param>
        /// <exception cref="MemoryAllocationException">メモリを確保できなかった時</exception>
        GenericFastString(
            GenericFastString const& right
        );

        /// <summary>
        /// 右辺値から文字列を移動
        /// </summary>
        /// <param name="right">ムーブする値</param>
        constexpr GenericFastString(
            GenericFastString&& right
        ) noexcept;

        /// <summary>
        /// 確保したメモリの開放
        /// </summary>
        constexpr ~GenericFastString();

        GenericFastString& operator=(
            Base const& right
        );

        GenericFastString& operator=(
            GenericFastString const& right
        );

        constexpr GenericFastString& operator=(
            GenericFastString&& right
        ) noexcept;

        /// <summary>
        /// Cスタイル文字列を取得
        /// </summary>
        /// <returns>Cスタイル文字列へのポインター</returns>
        [[nodiscard]] constexpr const ElementType* c_str() const noexcept;
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    template <ssize_t N>
    GenericFastString<TChar> GenericFastString<TChar>::FromLiteral(
        const ElementType(&arr)[N]
    )
    {
        return GenericFastString<TChar>(
            N - 1,
            &arr[0],
            {}
        );
    }

    template <CChar TChar>
    constexpr GenericFastString<TChar> GenericFastString<TChar>::FromMemoryUnsafe(
        GenericStringMemory<TChar> const& memory
    ) noexcept
    {
        return GenericFastString<TChar>(
            memory.Capacity() - 1,
            memory.Pointer(),
            {}
        );
    }

    template <CChar TChar>
    constexpr GenericFastString<TChar>::GenericFastString() noexcept
        : Base(
            0,
            static_cast<const ElementType*>(nullptr)
        )
    {
    }

    template <CChar TChar>
    GenericFastString<TChar>::GenericFastString(
        Base const& right
    )
        : GenericFastString(
            right.Length(),
            right.Data(),
            {}
        )
    {
    }

    template <CChar TChar>
    GenericFastString<TChar>::GenericFastString(
        GenericFastString<TChar> const& right
    )
        : GenericFastString(
            static_cast<Base const&>(right)
        )
    {
    }

    template <CChar TChar>
    constexpr GenericFastString<TChar>::GenericFastString(
        GenericFastString<TChar>&& right
    ) noexcept
        : Base(
            right.Length(),
            right.Data()
        )
    {
        right.m_p = nullptr;
    }

    template <CChar TChar>
    constexpr GenericFastString<TChar>::~GenericFastString()
    {
        if (this->m_p == nullptr) return;
        delete[] this->m_p;
    }

    template <CChar TChar>
    GenericFastString<TChar>& GenericFastString<TChar>::operator=(
        GenericFastString<TChar> const& right
    )
    {
        return operator=(static_cast<Base const&>(right));
    }

    template <CChar TChar>
    constexpr GenericFastString<TChar>& GenericFastString<TChar>::operator=(
        GenericFastString<TChar>&& right
    ) noexcept
    {
        delete[] this->m_p;
        this->m_p = right.m_p;
        this->m_length = right.m_length;

        right.m_p = nullptr;

        return *this;
    }

    template <CChar TChar>
    constexpr const typename GenericFastString<TChar>::ElementType*
    GenericFastString<TChar>::c_str() const noexcept
    {
        return this->m_p;
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICFASTSTRING_H