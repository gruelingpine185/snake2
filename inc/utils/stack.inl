#include "stack.h"


namespace s2 {    
    template <typename T, std::size_t N>
    stack<T, N>::stack(const stack<T, N>& _stack) noexcept:
        _data(_stack._data), _top(nullptr) {}

    template <typename T, std::size_t N>
    stack<T, N>::stack() noexcept:
        _data{}, _top(nullptr) {}

    template <typename T, std::size_t N>
    stack<T, N>::~stack() noexcept {}

    template <typename T, std::size_t N>
    bool stack<T, N>::push(const T& _data) noexcept {
        if(this->is_full()) return false;
        if(this->is_empty()) this->_top = &this->_data[0];

        *(this->_top++) = _data;
        return true;
    }

    template <typename T, std::size_t N>
    bool stack<T, N>::pop() noexcept {
        if(this->is_empty()) {
            this->_top = nullptr;
            return false;
        }

        this->_top--;
        return true;
    }

    template <typename T, std::size_t N>
    T& stack<T, N>::top() noexcept {
        return *(this->_top - 1);
    }

    template <typename T, std::size_t N>
    const T& stack<T, N>::top() const noexcept {
        return *this->_top;
    }

    template <typename T, std::size_t N>
    bool stack<T, N>::is_empty() const noexcept {
        return (this->_top == nullptr);
    }

    template <typename T, std::size_t N>
    bool stack<T, N>::is_full() const noexcept {
        return (this->_top == &this->_data[N]);
    }
}
