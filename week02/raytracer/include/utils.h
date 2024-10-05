//
// Created by stg05 on 14.09.2024.
//

#ifndef MAIN_UTILS_H
#define MAIN_UTILS_H

#include "transformations.h"

class sequence_renderer {
public:
    explicit sequence_renderer();
    void render_frame(const scene&) const;
private:
    const std::string path = "out";
    unsigned mutable frame_counter = 1;
};

void write_image(std::ofstream &os, scene &s);

void write_color(std::ostream &out, const color &pixel_color);

#endif //MAIN_UTILS_H
