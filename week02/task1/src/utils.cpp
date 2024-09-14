//
// Created by stg05 on 14.09.2024.
//

#include <fstream>
#include <iostream>
#include "../include/utils.h"

void write_image(std::ofstream &os) {
    os << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";
    const color c_left{1, 0, 0};
    const color c_right{0, 1, 0};
    for (int j = 0; j < HEIGHT; j++) {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < WIDTH; i++) {
            write_color(os, color2bw(gradient_horizontal(c_left, c_right, i, j)));
        }
    }
    std::clog << "\rDone.\n";
}

void write_color(std::ostream &out, const color &pixel_color) {
    out << print_color(pixel_color) << "\n";
}