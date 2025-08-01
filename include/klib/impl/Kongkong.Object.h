#ifndef KLIB_KONGKONG_OBJECT_H
#define KLIB_KONGKONG_OBJECT_H

#include "base.h"
#include <atomic>

#define KLIB_KONGKONG_OBJECT_OMAJINAI(type, base) \
    constexpr type(::std::nullptr_t) noexcept : base(nullptr) {} \
    [[nodiscard]] constexpr ImplType* operator->() const noexcept { return static_cast<ImplType*>(Object::GetPointer()); }
    
namespace klib::Kongkong
{
    /// <summary>
    /// JavaやC#のObjectに似た型
    /// </summary>
    class Object {
        friend constexpr bool operator==(Object const&, Object const&) noexcept;
        friend constexpr bool operator==(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator==(::std::nullptr_t, Object const&) noexcept;
        friend constexpr bool operator!=(Object const&, Object const&) noexcept;
        friend constexpr bool operator!=(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator!=(::std::nullptr_t, Object const&) noexcept;
        friend constexpr bool operator<(Object const&, Object const&) noexcept;
        friend constexpr bool operator<(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator<(::std::nullptr_t, Object const&) noexcept;
        friend constexpr bool operator<=(Object const&, Object const&) noexcept;
        friend constexpr bool operator<=(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator<=(::std::nullptr_t, Object const&) noexcept;
        friend constexpr bool operator>(Object const&, Object const&) noexcept;
        friend constexpr bool operator>(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator>(::std::nullptr_t, Object const&) noexcept;
        friend constexpr bool operator>=(Object const&, Object const&) noexcept;
        friend constexpr bool operator>=(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator>=(::std::nullptr_t, Object const&) noexcept;
        friend constexpr ::std::strong_ordering operator<=>(Object const&, Object const&) noexcept;
        friend constexpr ::std::strong_ordering operator<=>(Object const&, ::std::nullptr_t) noexcept;
        friend constexpr ::std::strong_ordering operator<=>(::std::nullptr_t, Object const&) noexcept;
    private:
        /// <summary>
        /// 参照カウンター
        /// </summary>
        struct RefCounter {
        private:
            
            /// <summary>
            /// 参照カウント
            /// </summary>
            ::std::atomic<uint64_t> m_refCount;

        public:

            /// <summary>
            /// 参照カウントがこの値の場合はdeleteしない
            /// </summary>
            /// <returns>deleteすべきでない参照カウント</returns>
            [[nodiscard]] static constexpr uint64_t NonDeleteCount() noexcept;

            /// <summary>
            /// 参照カウントを1増やす
            /// </summary>
            /// <returns>変更後の参照カウント</returns>
            uint64_t operator++() noexcept;

            /// <summary>
            /// 参照カウントを1減らす
            /// </summary>
            /// <returns>変更後の参照カウント</returns>
            uint64_t operator--() noexcept;

            /// <summary>
            /// 参照カウントを取得
            /// </summary>
            /// <returns>参照カウント</returns>
            [[nodiscard]] uint64_t GetCount() const noexcept;
        };
    protected:

        struct ImplType {
            friend Object;
        private:
            RefCounter m_counter;

        public:

            virtual ~ImplType() = default;

            /// <summary>
            /// このオブジェクトの参照カウントを取得
            /// </summary>
            /// <returns>参照カウント</returns>
            [[nodiscard]] uint64_t ReferenceCount() const noexcept;

            /// <summary>
            /// 文字列に変換
            /// </summary>
            /// <returns></returns>
            [[nodiscard]] virtual String ToString() const;
        };

    private:

        /// <summary>
        /// ポインターなクラス
        /// </summary>
        struct Pointer {
        private:
            /// <summary>
            /// 実態へのポインター
            /// </summary>
            ImplType* m_p;

        public:
            constexpr Pointer(ImplType* p) noexcept;
            constexpr Pointer(::std::nullptr_t) noexcept;
            Pointer(Pointer const& right) noexcept;
            constexpr Pointer(Pointer&& right) noexcept;

        public:
            ~Pointer();

            /// <summary>
            /// 実態へのポインターを取得
            /// </summary>
            /// <returns>実態へのポインター</returns>
            [[nodiscard]] constexpr ImplType* GetPointer() const noexcept;
        };
        
        Pointer m_p;

    protected:

        /// <summary>
        /// 参照カウントを1増やす
        /// </summary>
        /// <param name="p">ターゲット</param>
        /// <returns>変更後の参照カウント</returns>
        static uint64_t AddRef(ImplType* p) noexcept;

        /// <summary>
        /// 参照カウントを1減らす
        /// </summary>
        /// <param name="p">ターゲット</param>
        /// <returns>変更後の参照カウント</returns>
        static uint64_t RemRef(ImplType* p) noexcept;

        /// <summary>
        /// 実態へのポインターを取得
        /// </summary>
        /// <returns>実態へのポインター</returns>
        [[nodiscard]] constexpr ImplType* GetPointer() const noexcept;

    public:

        Object();
        constexpr Object(::std::nullptr_t) noexcept;

        template <class TObj> requires ::std::derived_from<TObj, Object>
        TObj As() const;
    };

    [[nodiscard]] constexpr bool operator==(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator==(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr bool operator==(::std::nullptr_t, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator!=(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator!=(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr bool operator!=(::std::nullptr_t, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator<(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator<(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr bool operator<(::std::nullptr_t, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator<=(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator<=(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr bool operator<=(::std::nullptr_t, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator>(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator>(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr bool operator>(::std::nullptr_t, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator>=(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr bool operator>=(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr bool operator>=(::std::nullptr_t, Object const& right) noexcept;
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(Object const& left, Object const& right) noexcept;
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(Object const& left, ::std::nullptr_t) noexcept;
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(::std::nullptr_t, Object const& right) noexcept;
}

namespace klib::Kongkong
{
    constexpr uint64_t Object::RefCounter::NonDeleteCount() noexcept
    {
        return ULLONG_MAX;
    }

    constexpr Object::Pointer::Pointer(Object::ImplType* p) noexcept
        : m_p(p)
    {
    }

    constexpr Object::Pointer::Pointer(::std::nullptr_t) noexcept
        : m_p(nullptr)
    {
    }

    constexpr Object::Pointer::Pointer(Object::Pointer&& right) noexcept
        : m_p(right.m_p)
    {
        right.m_p = nullptr;
    }

    constexpr Object::ImplType* Object::Pointer::GetPointer() const noexcept
    {
        return m_p;
    }

    inline uint64_t Object::AddRef(Object::ImplType* p) noexcept
    {
        return p->m_counter.operator++();
    }

    inline uint64_t Object::RemRef(Object::ImplType* p) noexcept
    {
        return p->m_counter.operator--();
    }

    constexpr Object::ImplType* Object::GetPointer() const noexcept
    {
        return m_p.GetPointer();
    }

    constexpr bool operator==(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() == right.GetPointer();
    }

    constexpr bool operator==(Object const& left, ::std::nullptr_t) noexcept
    {
        return left.GetPointer() == nullptr;
    }

    constexpr bool operator==(::std::nullptr_t, Object const& right) noexcept
    {
        return nullptr == right.GetPointer();
    }

    constexpr bool operator!=(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() != right.GetPointer();
    }

    constexpr bool operator!=(Object const& left, ::std::nullptr_t) noexcept
    {
        return left.GetPointer() != nullptr;
    }

    constexpr bool operator!=(::std::nullptr_t, Object const& right) noexcept
    {
        return nullptr != right.GetPointer();
    }

    constexpr bool operator<(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() < right.GetPointer();
    }

    constexpr bool operator<(Object const& left, ::std::nullptr_t) noexcept
    {
        return false;
    }

    constexpr bool operator<(::std::nullptr_t, Object const& right) noexcept
    {
        return nullptr != right.GetPointer();
    }

    constexpr bool operator<=(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() <= right.GetPointer();
    }

    constexpr bool operator<=(Object const& left, ::std::nullptr_t) noexcept
    {
        return left.GetPointer() == nullptr;
    }

    constexpr bool operator<=(::std::nullptr_t, Object const& right) noexcept
    {
        return true;
    }

    constexpr bool operator>(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() > right.GetPointer();
    }

    constexpr bool operator>(Object const& left, ::std::nullptr_t) noexcept
    {
        return left.GetPointer() != nullptr;
    }

    constexpr bool operator>(::std::nullptr_t, Object const& right) noexcept
    {
        return false;
    }

    constexpr bool operator>=(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() >= right.GetPointer();
    }

    constexpr bool operator>=(Object const& left, ::std::nullptr_t) noexcept
    {
        return true;
    }

    constexpr bool operator>=(::std::nullptr_t, Object const& right) noexcept
    {
        return nullptr == right.GetPointer();
    }

    constexpr ::std::strong_ordering operator<=>(Object const& left, Object const& right) noexcept
    {
        return left.GetPointer() <=> right.GetPointer();
    }

    constexpr ::std::strong_ordering operator<=>(Object const& left, ::std::nullptr_t) noexcept
    {
        return left.GetPointer() <=> nullptr;
    }

    constexpr ::std::strong_ordering operator<=>(::std::nullptr_t, Object const& right) noexcept
    {
        return nullptr <=> right.GetPointer();
    }
}

#endif //!KLIB_KONGKONG_OBJECT_H