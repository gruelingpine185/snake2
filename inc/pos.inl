#include "pos.h"


namespace s2 {
    template <typename T>
    pos<T>::pos(const T _x, const T _y) noexcept:
        _x(_x), _y(_y) {}

    template <typename T>
    pos<T>::pos(const T _n) noexcept:
        _x(_n), _y(_n) {}

    template <typename T>
    pos<T>::pos(const pos& _pos) noexcept:
        _x(_pos._x), _y(_pos._y) {}

    template <typename T>
    pos<T>::pos() noexcept {}

    template <typename T>
    pos<T>::~pos() noexcept {}

    template <typename T>
    T pos<T>::x() const noexcept {
        return this->_x;
    }

    template <typename T>
    T pos<T>::y() const noexcept {
        return this->_y;
    }

    template <typename T>
    void pos<T>::set_x(const T _x) const noexcept {
        this->_x = _x;
    }
    
    template <typename T>
    void pos<T>::set_y(const T _y) const noexcept {
        this->_y = _y;
    }
}
