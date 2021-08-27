//
// Created by quentin on 17/08/2021.
//

#ifndef TEST_MANDELBROT_H
#define TEST_MANDELBROT_H

#include <SDL2/SDL.h>
#include <complex>

bool BelongsToMandelbrotSet(std::complex<double> c, int*);
void ColorFunctionMandelbrot(int z, int*);

#endif //TEST_MANDELBROT_H
