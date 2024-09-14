//
// Created by stg05 on 14.09.2024.
//

#include "vec3.h"
#include "params.h"

#ifndef MAIN_TRANSFORMATIONS_H
#define MAIN_TRANSFORMATIONS_H

#endif //MAIN_TRANSFORMATIONS_H

color gradient_vertical(const color& color_start, const color& color_end,
                        unsigned int x, unsigned int y);
color gradient_horizontal(const color&  color_start, const color& color_end,
                          unsigned int x, unsigned int y);
color invert_color(const color&);
color color2bw(const color&);