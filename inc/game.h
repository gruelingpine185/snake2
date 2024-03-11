#pragma once


#include <random>

#include "size.h"
#include "snake.h"


union SDL_Event;


namespace s2 {
    class game;


    class game {
    public:
        game(const size<float>& _cell_size) noexcept;
        ~game() noexcept;

        void handle_events(const SDL_Event& _event);
        void update(const float _dt) noexcept;
        bool render(SDL_Renderer* _renderer) noexcept;
    private:
        std::random_device _rnd_device;
        std::mt19937 _prng;        
        snake _snake;
    };
}
