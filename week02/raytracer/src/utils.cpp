//
// Created by stg05 on 14.09.2024.
//

#include <fstream>
#include <iostream>
#include "../include/utils.h"


void write_image(std::ofstream &os, const scene &s) {

    os << "P3\n" << s.width() << ' ' << s.height() << "\n255\n";
    for (int j = 0; j < s.height(); j++) {
        std::clog << "\rScanlines remaining: " << (s.height() - j) << ' ' << std::flush;
        for (int i = 0; i < s.width(); i++) {
            ray r = s.coords_to_ray(i, j);
            write_color(os, ray_color(r, s));
        }
    }
    std::clog << "\rDone.\n";
}

void write_color(std::ostream &out, const color &pixel_color) {
    out << print_color(pixel_color) << "\n";
}

sequence_renderer::sequence_renderer() {
    std::string command = "cd " + path + "&& del *.* /q /s";
    system(command.c_str());
}

void sequence_renderer::render_frame(const scene &s) const {
    std::string file_path(path + "\\f" + std::to_string(frame_counter) + ".ppm");
    frame_counter++;
    std::ofstream os(file_path);
    write_image(os, s);
}
