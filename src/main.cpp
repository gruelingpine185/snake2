#include <string>

#include <SDL3/SDL_events.h>

#include "window.h"


int main() {
    const std::string title = "Snake 2";
    constexpr int width = 1280 - (1280 / 4);
    constexpr int height = 720 - (720 / 4);

    s2::window win(title, width, height);
    if(!win.create()) return 1;
    if(!win.show()) return 1;

    while(!win.should_close()) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            win.handle_events(event);
        }
    }

    return 0;
}
