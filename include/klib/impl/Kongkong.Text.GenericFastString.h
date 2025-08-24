#ifndef KLIB_KONGKONG_TEXT_GENERICFASTSTRING_H
#define KLIB_KONGKONG_TEXT_GENERICFASTSTRING_H

#include "base.h"
#include "Kongkong.NonType.h"
#include "Kongkong.Text.GenericFastStringBase.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CChar TChar>
    struct GenericFastString : public GenericFastStringBase<TChar> {
    public:
        using Base = GenericFastStringBase<TChar>;
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
        /// 文字列をコピー
        /// </summary>
        /// <param name="right">コピー元の値</param>
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
    GenericFastString<TChar>::GenericFastString(
        GenericFastString<TChar> const& right
    )
        : GenericFastString(
            right.Length(),
            right.Data(),
            {}
        )
    {
    }

    template <CChar TChar>
    constexpr GenericFastString<TChar>::GenericFastString(
        GenericFastString<TChar> && right
    )
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
    constexpr GenericFastString<TChar>& GenericFastString<TChar>::operator=(
        GenericFastString<TChar>&& right
    )
    {
        delete[] this->m_p;
        this->m_p = right.m_p;
        this->m_length = right.m_length;

        right.m_p = nullptr;

        return *this;
    }

    template <CChar TChar>
    constexpr const GenericFastString<TChar>::ElementType* GenericFastString<TChar>::c_str() const noexcept
    {
        return this->m_p;
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICFASTSTRING_H