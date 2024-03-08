#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#include "window.h"


namespace s2 {
    static constexpr uint32_t sdl_enabled_systems = SDL_INIT_VIDEO;


    window::window(const std::string& _title, const int _w, const int _h):
        _window(nullptr), _renderer(nullptr), _title(_title),
        _width(_w), _height(_h), _should_close(false) {}

    window::window() noexcept:
        _window(nullptr), _renderer(nullptr), _title(""),
        _width(800), _height(600), _should_close(false) {}

    window::~window() noexcept {
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyWindow(this->_window);
        SDL_QuitSubSystem(sdl_enabled_systems);
        SDL_Quit();
    }
}
