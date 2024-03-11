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
    private:
        std::random_device _rnd_device;
        std::mt19937 _prng;        
        snake _snake;
    };
}
