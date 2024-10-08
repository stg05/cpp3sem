//
// Created by stg05 on 14.09.2024.
//

#include <iostream>
#include "../include/transformations.h"
#include <cmath>


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

color linear_fall_gradient(const color &c1, const color &c2, double alpha) {
    auto first_share = c1.length() / (c1.length() + c2.length());
    if (alpha < first_share) {
        auto beta = alpha / first_share;
        return (1-beta) * c1 + beta * colors::BLACK;
    } else {
        auto beta = (alpha - first_share) / (1 - first_share);
        return (1-beta) * colors::BLACK + (beta) * c2;
    }
}

color invert_color(const color &param) {
    return color{1.0, 1.0, 1.0} - param;
}

color color2bw(const color &param) {
    double avg = color{0.299, 0.587, 0.114} * param;
    return color{avg, avg, avg};
}

//color ray_color(const ray &r, const scene &s) {
//    vec3 unit_direction = r.get_dir().normalized();
//    auto a = 0.5 * (unit_direction.y() + 1.0);
//    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
//}

color ray_color(const ray &r, const scene &s) {
    vec3 unit_direction = r.get_dir().normalized();
    auto a = acos(unit_direction * vec3{0., 0, -1})/M_PI*2;
    if(int(180.0*a)%10 < 1){
        return colors::BLACK;
    }else{
        return colors::WHITE;
    }
    //return linear_fall_gradient(colors::GREEN, colors::RED, a);
}