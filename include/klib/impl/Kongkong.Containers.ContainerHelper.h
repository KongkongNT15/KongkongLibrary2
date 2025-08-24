#ifndef KLIB_KONGKONG_CONTAINTERS_CONTAINERHELPER_H
#define KLIB_KONGKONG_CONTAINTERS_CONTAINERHELPER_H

#include "base.h"

namespace klib::Kongkong::Containers
{
    class ContainerHelper final {
    public:

        KLIB_STATIC_CLASS(ContainerHelper);

        /// <summary>
        /// IndexOf()などで要素が見つからなかった時の戻り値
        /// </summary>
        [[nodiscard]] static consteval ssize_t NotFound() noexcept;
    };
}

namespace klib::Kongkong::Containers
{
    consteval ssize_t ContainerHelper::NotFound() noexcept
    {
        return -1;
    }
}

#endif //!KLIB_KONGKONG_CONTAINTERS_CONTAINERHELPER_H