//
// Created by stg05 on 14.09.2024.
//

#include <fstream>
#include <iostream>
#include "../include/utils.h"

void write_image(std::ofstream &os, scene &s) {

    os << "P3\n" << s.width() << ' ' << s.height() << "\n255\n";
    for (int j = 0; j < s.height(); j++) {
        std::clog << "\rScanlines remaining: " << (s.height() - j) << ' ' << std::flush;
        for (int i = 0; i < s.width(); i++) {
            ray r = s.cds_to_ray(i, j);
            write_color(os, ray_color(r, s));
        }
    }
    std::clog << "\rDone.\n";
}

void write_color(std::ostream &out, const color &pixel_color) {
    out << print_color(pixel_color) << "\n";
}