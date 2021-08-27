#include "mandelbrot.h"
#include "App.h"
#include <csignal>

void signalHandler(int);

int main(){

    App* app = new App( SDL_INIT_VIDEO,
                        SDL_WINDOW_SHOWN,
                        SDL_RENDERER_ACCELERATED,
                        "Mandelbrot Set Visualizer",
                        0, 0,
                        800, 800);

    std::signal(SIGINT, signalHandler);

    app->run();

    delete app;

    return EXIT_SUCCESS;
}

void signalHandler(int s){
    exit(s);
}