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

    void game::handle_events(const SDL_Event& _event) {
        this->_snake.handle_events(_event);
    }

    void game::update(const float _dt) noexcept {
        this->_snake.update(_dt);
    }

    bool game::render(SDL_Renderer* _renderer) noexcept {
        if(!this->_snake.render(_renderer)) return false;

        return true;
    }
}