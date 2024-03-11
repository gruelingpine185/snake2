#include <SDL3/SDL_render.h>

#include "dir.h"
#include "snake.h"
#include "pos.inl"
#include "size.inl"


namespace s2 {
    snake::snake(const s2::size<float>& _size,
                 const s2::pos<float>& _pos,
                 const s2::dir _dir,
                 const std::uint32_t _len,
                 const float _vel) noexcept:
        _size(_size), _pos(_pos), _dir(_dir),
        _len(_len), _vel(_vel), _segments{} {}

    snake::~snake() noexcept {}

    s2::size<float> snake::size() const noexcept {
        return this->_size;
    }

    pos<float> snake::pos() const noexcept {
        return this->_pos;
    }

    s2::dir snake::dir() const noexcept {
        return this->_dir;
    }

    float snake::vel() const noexcept {
        return this->_vel;
    }

    std::uint32_t snake::len() const noexcept {
        return this->_len;
    }
}
