#include "stack.h"


namespace s2 {    
    template <typename T, std::size_t N>
    stack<T, N>::stack(const stack<T, N>& _stack) noexcept:
        _top(_stack._top), _data(_stack._data) {}

    template <typename T, std::size_t N>
    stack<T, N>::stack() noexcept:
        _top(nullptr), _data{} {}

    template <typename T, std::size_t N>
    stack<T, N>::~stack() noexcept {}
}
