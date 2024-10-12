//
// Created by stg05 on 14.09.2024.
//


#include "params.h"
#include "scene.h"

#ifndef MAIN_TRANSFORMATIONS_H
#define MAIN_TRANSFORMATIONS_H

color gradient_vertical(const color &color_start, const color &color_end,
                        unsigned int x, unsigned int y);

color gradient_horizontal(const color &color_start, const color &color_end,
                          unsigned int x, unsigned int y);

color linear_fall_gradient(const color &c1, const color &c2, double alpha);

color invert_color(const color &);

color color2bw(const color &);

color ray_color(const ray &, const scene &s, double t_min = 0, double t_max = 10000);

#endif //MAIN_TRANSFORMATIONS_H