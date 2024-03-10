#include "size.h"


namespace s2 {
    template <typename T>
    size<T>::size(const T _w, T _h) noexcept:
        _w(_w), _h(_h) {}

    template <typename T>
    size<T>::size(const T _n) noexcept:
        _w(_n), _h(_n) {}

    template <typename T>
    size<T>::size(const size& _size) noexcept:
        _w(_size._w), _h(_size._h) {}

    template <typename T>
    size<T>::size() noexcept {}

    template <typename T>
    size<T>::~size() noexcept {}

    template <typename T>
    T size<T>::w() const noexcept {
        return this->_w;
    }

    template <typename T>
    T size<T>::h() const noexcept {
        return this->_h;
    }

    template <typename T>
    void size<T>::set_w(const T _w) noexcept {
        this->_w = _w;
    }

    template <typename T>
    void size<T>::set_h(const T _h) noexcept {
        this->_h = _h;
    }
}
