#pragma once


#include <cstdint>
#include <array>

#include "pos.h"
#include "size.h"


struct SDL_Renderer;
union SDL_Event;


namespace s2 {
    class snake;
    enum class dir;


    class snake {
    public:
        snake(const s2::size<float>& _size,
              const s2::pos<float>& _pos,
              const s2::dir _dir,
              const std::uint32_t _len,
              const float _vel) noexcept;
        ~snake() noexcept;

        void handle_events(const SDL_Event& _event) noexcept;
        bool render(SDL_Renderer* _renderer) const noexcept;
        void update(const float _dt) noexcept;
        const s2::size<float> size() const noexcept;
        s2::pos<float>& pos() noexcept;
        const s2::pos<float> pos() const noexcept;
        s2::dir dir() const noexcept;
        float vel() const noexcept;
        std::uint32_t len() const noexcept;
    private:
        s2::size<float> _size;
        s2::pos<float> _pos;
        s2::dir _dir;
        std::uint32_t _len;
        float _vel;
        std::array<s2::pos<float>, 32>  _segments;
    };
}
