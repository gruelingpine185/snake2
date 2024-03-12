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

        bool push(const T& _data) noexcept;
        bool pop() noexcept;
        T& top() noexcept;
        const T& top() const noexcept;
        bool is_empty() const noexcept;
        bool is_full() const noexcept;
    private:
        T _data[N];
        T* _top;
    };
}
