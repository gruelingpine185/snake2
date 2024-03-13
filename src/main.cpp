#include <string>

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_events.h>

#include "window.h"
#include "game.h"
#include "pos.inl"
#include "size.inl"


int main() {
    const std::string title = "Snake 2";
    const s2::size<float> cell(16.0f);
    constexpr int scale = 4;
    
    s2::window win(title, cell.w() * (16 * scale), cell.h() * (9 * scale));  
    if(!win.create()) return 1;
    if(!win.show()) return 1;

    s2::game game(cell);
    float tick = 0.0f;

    while(!win.should_close()) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            win.handle_events(event);
            game.handle_events(event);
        }

        game.update(tick);
        if(!win.clear()) return 1;
        if(!game.render(win.renderer())) return 1;
        if(!win.render()) return 1;

        tick++;
    }

    return 0;
}
