#pragma once


#include <type_traits>


namespace s2 {
    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    class pos;


    template <typename T>
    class pos<T> {
    public:
        pos(const T _x, const T _y) noexcept;
        pos(const T _n) noexcept;
        pos(const pos& _pos) noexcept;
        pos() noexcept;
        ~pos() noexcept;
    private:
        T _x;
        T _y;
    };
}
