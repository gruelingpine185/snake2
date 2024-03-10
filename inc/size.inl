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
}
