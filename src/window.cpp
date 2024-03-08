#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

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

    bool window::create(const std::string& _title,
                          const int _w,
                          const int _h) {
        this->_title = _title;
        this->_width = _w;
        this->_height = _h;
        return this->create();
    }

    bool window::create() noexcept {
        if(SDL_InitSubSystem(sdl_enabled_systems) < 0) return false;

        this->_window = SDL_CreateWindow(this->_title.c_str(),
                                         this->_width,
                                         this->_height,
                                         SDL_WINDOW_HIDDEN);
        if(!this->_window) return false;

        this->_renderer = SDL_CreateRenderer(this->_window,
                                             NULL,
                                             SDL_RENDERER_PRESENTVSYNC);
        if(!this->_renderer) return false;

        return true;
    }

    bool window::show() noexcept {
        return (SDL_ShowWindow(this->_window) == 0);
    }

    bool window::hide() noexcept {
        return (SDL_HideWindow(this->_window) == 0);
    }

    bool window::should_close() noexcept {
        return this->_should_close;
    }

    void window::handle_events(const SDL_Event& _event) noexcept {
        switch(_event.type) {
            case SDL_EVENT_QUIT: this->_should_close = true; break;
            default: break;
        }
    }

    const std::string& window::title() const noexcept {
        return this->_title;
    }

    int window::width() const noexcept {
        return this->_width;
    }

    int window::height() const noexcept {
        return this->_height;
    }
}
