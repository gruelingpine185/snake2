#include <SDL3/SDL_render.h>

#include "dir.h"
#include "snake.h"
#include "pos.inl"
#include "size.inl"


namespace s2 {
    static bool draw_dir(SDL_Renderer* _renderer, const snake _s);


    static bool draw_dir(SDL_Renderer* _renderer, const snake _s) {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0x00, 0xff) < 0) {
            return false;
        }

        int res;
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
            default:
                res = 0;
                break;
        }

        return (res == 0);
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
                if(this->_dir != dir::down) this->_dir = dir::up;

                break;
            case SDLK_DOWN:
                if(this->_dir != dir::up) this->_dir = dir::down;

                break;
            case SDLK_LEFT:
                if(this->_dir != dir::right) this->_dir = dir::left;

                break;
            case SDLK_RIGHT:
                if(this->_dir != dir::left) this->_dir = dir::right;

                break;
            default:
                break;
        }
    }

    bool snake::render(SDL_Renderer* _renderer) const noexcept {
        if(SDL_SetRenderDrawColor(_renderer, 0xff, 0xff, 0xff, 0xff) < 0) {
            return false;
        }

        const SDL_FRect head = {_pos.x(), _pos.y(), _size.w(), _size.h()};
        if(SDL_RenderFillRect(_renderer, &head) < 0) return false;
        if(!draw_dir(_renderer, *this)) return false;

        return true;
    }

    void snake::update(const float _dt) noexcept {
        if(static_cast<int>(_dt) % 10) return;
    
        s2::pos<float> next_pos = {
            this->_size.w() * this->_vel,
            this->_size.h() * this->_vel
        };

        switch(this->_dir) {
            case dir::up:
                next_pos.set_x(0.0f);
                this->_pos -= next_pos;
                break;
            case dir::down:
                next_pos.set_x(0.0f);
                this->_pos += next_pos;
                break;
            case dir::left:
                next_pos.set_y(0.0f);
                this->_pos -= next_pos;
                break;
            case dir::right:
                next_pos.set_y(0.0f);
                this->_pos += next_pos;
                break;
            default:
                break;
        }
    }

    const s2::size<float> snake::size() const noexcept {
        return this->_size;
    }

    const pos<float> snake::pos() const noexcept {
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
