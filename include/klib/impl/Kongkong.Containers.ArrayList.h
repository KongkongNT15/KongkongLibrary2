#ifndef KLIB_KONGKONG_CONTAINERS_ARRAYLIST_H
#define KLIB_KONGKONG_CONTAINERS_ARRAYLIST_H

#include "base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Containers.s_arrayBase.h"
#include "Kongkong.Containers.ContainerHelper.h"

namespace klib::Kongkong::Containers
{
    template <class T>
    struct ArrayList : public ValueType, public s_arrayBase<T> {
    private:
        ssize_t m_capacity;
    public:

        constexpr ArrayList(
        ) noexcept;

        ~ArrayList();

        void Append(
        ) requires ::std::default_initializable<T>;

        void Append(
            T const& value
        ) requires ::std::copy_constructible<T>;

        void Append(
            T&& value
        ) requires ::std::move_constructible<T>;

        [[nodiscard]] constexpr ssize_t Capacity(
        ) const noexcept;

        template <class... Args>
        void Emplace(
            Args&&... args
        );
    };
}

namespace klib::Kongkong::Containers
{
    template <class T>
    constexpr ArrayList<T>::ArrayList(
    ) noexcept
        : s_arrayBase(
            0,
            nullptr
        )
    {
    }

    template <class T>
    void ArrayList<T>::Append(
    ) requires ::std::default_initializable<T>
    {
        Emplace();
    }

    template <class T>
    void ArrayList<T>::Append(
        T const& value
    ) requires ::std::copy_constructible<T>
    {
        Emplace(value);
    }

    template <class T>
    void ArrayList<T>::Append(
        T&& value
    ) requires ::std::move_constructible<T>
    {
        Emplace(::std::move(value));
    }

    template <class T>
    constexpr ssize_t ArrayList<T>::Capacity(
    ) const noexcept
    {
        return m_capacity;
    }
}

#endif //!KLIB_KONGKONG_CONTAINERS_ARRAYLIST_H