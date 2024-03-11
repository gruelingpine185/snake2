#include "snake.h"
#include "dir.h"
#include "pos.inl"
#include "size.inl"
#include "game.h"


namespace s2 {
    game::game(const size<float>& _cell_size) noexcept:
        _rnd_device{}, _prng(_rnd_device()),
        _snake(_cell_size, {0, 0}, static_cast<enum s2::dir>(_prng()), 3, 1.0f)
        {}

    game::~game() noexcept {}
}
