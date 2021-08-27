//
// Created by quentin on 17/08/2021.
//

#include "mandelbrot.h"

bool BelongsToMandelbrotSet(std::complex<double> c, int* z_return){
    std::complex<double> z = std::complex<double>(0);
    *z_return = 0;

    for(int i = 0; i < 20; i++){
        z = z*z + c;
        *z_return +=1;
        if(std::norm(z) > 2) return false;
    }

    return true;
}

/**
 * Colors the orbits
 * @param z orbit
 * @param color reference to color array
 */
void ColorFunctionMandelbrot(int z, int* color){
    const int r[16u] = {245, 40, 52, 107, 159, 143, 58, 129, 154, 108, 154, 96, 61, 60, 14, 115};
    const int g[16u] = {85, 50, 147, 249, 244, 25, 19, 196, 230, 61, 206, 38, 226, 98, 111, 40};
    const int b[16u] = {15, 191, 46, 107, 23, 83, 32, 231, 126, 4, 48, 34, 104, 209, 46, 90};

    color[0] = r[z%16];
    color[1] = g[z%16];
    color[2] = b[z%16];
}