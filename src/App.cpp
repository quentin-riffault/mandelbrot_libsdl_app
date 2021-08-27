#include "App.h"
#include "mandelbrot.h"
#include <SDL2/SDL.h>
#include <csignal>

#define MANDELBROT_X_BOUNDARY 1.5
#define MANDELBROT_Y_BOUNDARY 1.5
#define FPS (1/24)*1000

App::App(   Uint32 init_flags,
            Uint32 window_flags,
            Uint32 renderer_flags,
            const char* win_title,
            int x, int y,
            int w, int h) : SDL_App::SDL_app(   init_flags,
                                                window_flags,
                                                renderer_flags,
                                                win_title,
                                                x, y,
                                                w, h ){

}

void App::destroy(){

}

SDL_bool App::events(){

    SDL_Event events;

    while(SDL_PollEvent(&events)){
        switch(events.type){
            case SDL_WINDOWEVENT:
                if(events.window.event == SDL_WINDOWEVENT_CLOSE)
                    return SDL_FALSE;
                break;
        }
    }

    return SDL_TRUE;
}

void App::draw(){
    static bool drawn = false;
    if(drawn) return;

    int ir = 0, jr = 0;

    const double x = MANDELBROT_X_BOUNDARY, y = MANDELBROT_Y_BOUNDARY;
    int w, h;

    getWindowSize(&w, &h);
    SDL_Renderer* r = getMainRenderer();

    for(double i = -x; i <= x; i+=2*x/w, ir++){
        for(double j = -y; j <= y; j += 2*y/h, jr++){

            std::complex<double> c = std::complex<double>(i, j);
            int z = 0;

            if (BelongsToMandelbrotSet(c, &z)) SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
            else {

                int colors[3] = {0};
                ColorFunctionMandelbrot(z, colors);
                SDL_SetRenderDrawColor(r, colors[0], colors[1], colors[2], 255);
            }

            SDL_RenderDrawPoint(r, ir, jr);
        }
        jr = 0;
    }

    drawn = true;
}

void App::render(){
    SDL_Delay(FPS);
    SDL_RenderPresent(getMainRenderer());

}

App::~App(){

}