#pragma once


#include <type_traits>


namespace s2 {
    template <
        typename T,
        typename = typename std::enable_if_t<std::is_arithmetic_v<T>>
    >
    class size;


    template <typename T>
    class size<T> {
    public:
        size(const T _w, T _h) noexcept;
        size(const T _n) noexcept;
        size(const size& _size) noexcept;
        size() noexcept;
        ~size() noexcept;

        T w() const noexcept;
        T h() const noexcept;
        void set_w(const T _w) noexcept;
        void set_h(const T _h) noexcept;

        size& operator= (const size& _size) noexcept;

        template <typename>
        friend bool operator== (const size<T>& _l, const size<T>& _r) noexcept;
        template <typename>
        friend bool operator!= (const size<T>& _l, const size<T>& _r) noexcept;
    private:
        T _w;
        T _h;
    };
}
