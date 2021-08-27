//
// Created by quentin on 26/08/2021.
//

#ifndef MANDELBROT_SDL_APP_TEST_APP_H
#define MANDELBROT_SDL_APP_TEST_APP_H

#include <SDL_app.h>

class App : public SDL_App::SDL_app{

private:
    void destroy();

    SDL_bool events();
    void draw();
    void render();

public:
    App(Uint32 init_flags,
        Uint32 window_flags,
        Uint32 renderer_flags,
        const char* win_title,
        int x, int y,
        int w, int h);
    virtual ~App();
};

#endif //MANDELBROT_SDL_APP_TEST_APP_H
