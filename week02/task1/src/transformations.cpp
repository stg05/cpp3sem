//
// Created by stg05 on 14.09.2024.
//

#include "../include/transformations.h"


color gradient_vertical(const color &color_start, const color &color_end,
                        unsigned int x, unsigned int y) {
    double y_rel = ((double) y) / HEIGHT;

    return ((1.0 - y_rel) * color_start) + ((y_rel) * color_end);
}

color gradient_horizontal(const color &color_start, const color &color_end,
                          unsigned int x, unsigned int y) {
    double x_rel = ((double) x) / WIDTH;
    return ((1.0 - x_rel) * color_start) + ((x_rel) * color_end);
}

color invert_color(const color &param) {
    return color{1.0, 1.0, 1.0} - param;
}

color color2bw(const color &param) {
    double avg = color{0.299, 0.587, 0.114} * param;
    return color{avg, avg, avg};
}