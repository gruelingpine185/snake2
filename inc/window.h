#pragma once


#include <string>


struct SDL_Window;
struct SDL_Renderer;
union SDL_Event;


namespace s2 {
    class window;


    class window {
    public:
        window(const std::string& _title, const int _w, const int _h);
        window(const window& _win) = delete;
        window() noexcept;
        ~window() noexcept;

        bool create(const std::string& _title,
                              const int _w,
                              const int _h);
        bool create() noexcept;
        bool show() noexcept;
        bool hide() noexcept;
        bool should_close() noexcept;
        bool render() noexcept;
        void handle_events(const SDL_Event& _event) noexcept;

        const std::string& title() const noexcept;
        int width() const noexcept;
        int height() const noexcept;

        window& operator= (const window& _win) = delete;
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        std::string _title;
        int _width;
        int _height;
        bool _should_close;
        
    };
}
