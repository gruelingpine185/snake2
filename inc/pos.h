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

        T x() const noexcept;
        T y() const noexcept;
        void set_x(const T _x) noexcept;
        void set_y(const T _y) noexcept;

        pos& operator= (const pos& _pos) noexcept;
        pos& operator+= (const pos& _r) noexcept;
        pos& operator-= (const pos& _r) noexcept;
    private:
        T _x;
        T _y;
    };

    template <typename T>
    bool operator== (const pos<T>& _l, const pos<T>& _r) noexcept;
    template <typename T>
    bool operator!= (const pos<T>& _l, const pos<T>& _r) noexcept;
    template <typename T>
    pos<T> operator+ (const pos<T>& _l, const pos<T>& _r) noexcept;
    template <typename T>
    pos<T> operator- (const pos<T>& _l, const pos<T>& _r) noexcept;
}
