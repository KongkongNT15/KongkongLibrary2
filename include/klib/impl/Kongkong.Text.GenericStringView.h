#ifndef KLIB_KONGKONG_TEXT_GENERICSTRINGVIEW_H
#define KLIB_KONGKONG_TEXT_GENERICSTRINGVIEW_H

#include "base.h"
#include "Kongkong.Text.GenericFastStringBase.h"

namespace klib::Kongkong::Text
{
    /// <summary>
    /// 文字列ビュー
    /// </summary>
    /// <typeparam name="TChar">文字型</typeparam>
    template <CChar TChar>
    struct GenericStringView final : public GenericFastStringBase<TChar> {
    public:
        /// <summary>
        /// 基底クラス
        /// </summary>
        using Base = GenericFastStringBase<TChar>;

        /// <summary>
        /// 要素型
        /// </summary>
        using ElementType = typename Base::ElementType;
    private:

        /// <summary>
        /// 安全性を確認せずにオブジェクトを構築
        /// </summary>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="nonType">使わない型</param>
        explicit constexpr GenericStringView(
            const ElementType* p,
            NonType nonType
        ) noexcept;

        /// <summary>
        /// 安全性を確認せずにオブジェクトを構築
        /// </summary>
        /// <param name="length">参照する文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <param name="nonType">使わない型</param>
        explicit constexpr GenericStringView(
            ssize_t length,
            const ElementType* p,
            NonType nonType
        ) noexcept;

    public:

        /// <summary>
        /// 安全性を確認せずにオブジェクトを構築
        /// </summary>
        /// <param name="p">文字列へのポインター</param>
        /// <returns>構築されたオブジェクト</returns>
        [[nodiscard]] static constexpr GenericStringView CreateUnsafe(
            const ElementType* p
        ) noexcept;

        /// <summary>
        /// 安全性を確認せずにオブジェクトを構築
        /// </summary>
        /// <param name="length">参照する文字列の長さ</param>
        /// <param name="p">文字列へのポインター</param>
        /// <returns>構築されたオブジェクト</returns>
        [[nodiscard]] static constexpr GenericStringView CreateUnsafe(
            ssize_t length,
            const ElementType* p
        ) noexcept;

        GenericStringView(GenericStringView const&) = default;
        GenericStringView(GenericStringView&&) = default;

        GenericStringView& operator=(GenericStringView const&) = default;
        GenericStringView& operator=(GenericStringView&&) = default;

        
    };
}

namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr GenericStringView<TChar>::GenericStringView(
        const ElementType* p,
        NonType
    ) noexcept
        : Base(
            StringHelper::GetLengthUnsafe(p),
            p
        )
    {
    }

    template <CChar TChar>
    constexpr GenericStringView<TChar>::GenericStringView(
        ssize_t length,
        const ElementType* p,
        NonType
    ) noexcept
        : Base(
            length,
            p
        )
    {
    }

    template <CChar TChar>
    constexpr GenericStringView<TChar> GenericStringView<TChar>::CreateUnsafe(
        const ElementType* p
    ) noexcept
    {
        return GenericStringView<TChar>(p, {});
    }

    template <CChar TChar>
    constexpr GenericStringView<TChar> GenericStringView<TChar>::CreateUnsafe(
        ssize_t length,
        const ElementType* p
    ) noexcept
    {
        return GenericStringView<TChar>(length, p, {});
    }

}

// GenericFastStringBase<TChar>の一部のメンバー関数を実装
namespace klib::Kongkong::Text
{
    template <CChar TChar>
    constexpr GenericStringView<TChar> GenericFastStringBase<TChar>::GetView() const noexcept
    {
        return GenericStringView<TChar>::CreateUnsafe(
            m_length,
            m_p
        );
    }
}

#endif //!KLIB_KONGKONG_TEXT_GENERICSTRINGVIEW_H