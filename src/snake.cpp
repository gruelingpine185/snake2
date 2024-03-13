#include <iostream>

#include <SDL3/SDL_render.h>

#include "dir.h"
#include "snake.h"
#include "pos.inl"
#include "size.inl"


namespace s2 {
    static uint32_t count = 1;
    static bool draw_dir(SDL_Renderer* _renderer, const snake& _s);
    static pos<float> calc_next_pos(const size<float>& _size,
                                    const pos<float>& _pos,
                                    const dir _dir,
                                    const float _vel);


    static bool draw_dir(SDL_Renderer* _renderer, const snake& _s) {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0x00, 0xff) < 0) {
            return false;
        }
            
        int res = 0;
        switch(_s.dir()) {
            case dir::up:
                res = SDL_RenderLine(_renderer,
                                     _s.pos().x() + (_s.size().w() / 2) - 0.5f,
                                     _s.pos().y(),
                                     _s.pos().x() + (_s.size().w() / 2) - 0.5f,
                                     _s.pos().y() - _s.size().h());
                break;
            case dir::down:
                res = SDL_RenderLine(_renderer,
                                     _s.pos().x() + (_s.size().w() / 2) - 0.5f,
                                     _s.pos().y() + _s.size().h(),
                                     _s.pos().x() + (_s.size().w() / 2) - 0.5f,
                                     _s.pos().y() + (_s.size().h() * 2));
                break;
            case dir::left:
                res = SDL_RenderLine(_renderer,
                                     _s.pos().x(),
                                     _s.pos().y() + (_s.size().h() / 2) - 0.5f,
                                     _s.pos().x() - _s.size().w(),
                                     _s.pos().y() + (_s.size().h() / 2) - 0.5f);
                break;
            case dir::right:
                res = SDL_RenderLine(_renderer,
                                     _s.pos().x() + _s.size().w(),
                                     _s.pos().y() + (_s.size().h() / 2) - 0.5f,
                                     _s.pos().x() + (_s.size().w() * 2),
                                     _s.pos().y() + (_s.size().h() / 2) - 0.5f);
                break;
        }

        return (res == 0);
    }

    static pos<float> calc_next_pos(const size<float>& _size,
                                    const pos<float>& _pos,
                                    const dir _dir,
                                    const float _vel) {
        
        pos<float> offset = {_size.w() * _vel, _size.h() * _vel};
        (is_direction_on_xaxis(_dir))?
            offset.set_y(0.0f):
            offset.set_x(0.0f);
        return (_dir == dir::left || _dir == dir::up)?
            (_pos - offset):
            (_pos + offset);
    }


    snake::snake(const s2::size<float>& _size,
                 const s2::pos<float>& _pos,
                 const s2::dir _dir,
                 const std::uint32_t _len,
                 const float _vel) noexcept:
        _size(_size), _pos(_pos), _dir(_dir),
        _len(_len), _vel(_vel), _segments{} {}

    snake::~snake() noexcept {}

    void snake::handle_events(const SDL_Event& _event) noexcept {
        if(_event.type != SDL_EVENT_KEY_DOWN) return;
        
        switch(_event.key.keysym.sym) {
            case SDLK_UP:
                if(is_direction_on_xaxis(this->_dir)) this->_dir = dir::up;
                break;
            case SDLK_DOWN:
                if(is_direction_on_xaxis(this->_dir)) this->_dir = dir::down;
                break;
            case SDLK_LEFT:
                if(is_direction_on_yaxis(this->_dir)) this->_dir = dir::left;
                break;
            case SDLK_RIGHT:
                if(is_direction_on_yaxis(this->_dir)) this->_dir = dir::right;
                break;
        }

        if(count == this->_segments.size()) return;

        this->_segments[count++] = this->_pos;
    }

    bool snake::render(SDL_Renderer* _renderer) const noexcept {
        SDL_SetRenderDrawColor(_renderer, 0xff, 0x00, 0x00, 0xff);
        for(size_t i = 0; i < count; i++) {
            SDL_FRect rect;
            rect.x = this->_segments[i].x();
            rect.y = this->_segments[i].y();
            rect.w = this->_size.w();
            rect.h = this->_size.h();
            SDL_RenderFillRect(_renderer, &rect);
        }

        const SDL_FRect head = {_pos.x(), _pos.y(), _size.w(), _size.h()};
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0xff, 0xff) < 0) {
            return false;
        }

        if(SDL_RenderFillRect(_renderer, &head) < 0) return false;
        if(!draw_dir(_renderer, *this)) return false;

        return true;
    }

    void snake::update(const float _dt) noexcept {
        if(static_cast<int>(_dt) % 10) return;

        this->_segments[0] = this->_pos;
        this->_pos = calc_next_pos(this->_size,
                                   this->_pos,
                                   this->_dir,
                                   this->_vel);
    }

    const s2::size<float> snake::size() const noexcept {
        return this->_size;
    }

    s2::pos<float>& snake::pos() noexcept {
        return this->_pos;
    }
    const s2::pos<float> snake::pos() const noexcept {
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
