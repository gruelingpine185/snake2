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

    template <typename T>
    size<T>& size<T>::operator= (const size& _size) noexcept {
        if(*this == _size) return *this;

        this->_w = _size._w;
        this->_h = _size._h;
        return *this;
    }

    template <typename T>
    bool operator== (const size<T>& _l, const size<T>& _r) noexcept {
        return ((_l._w == _r._w) && (_l._h == _r._h));
    }

    template <typename T>
    bool operator!= (const size<T>& _l, const size<T>& _r) noexcept {
        return (!(_l == _r));
    }
}
