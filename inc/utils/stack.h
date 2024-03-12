#pragma once


#include <cstddef>


namespace s2 {
    template <typename T, std::size_t N>
    class stack;


    template <typename T, std::size_t N>
    class stack {
    public:
        stack(const stack& _stack) noexcept;
        stack() noexcept;
        ~stack() noexcept;
    private:
        T _data[N];
        T* _top;
    };
}
