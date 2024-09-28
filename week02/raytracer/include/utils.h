//
// Created by stg05 on 14.09.2024.
//

#ifndef MAIN_UTILS_H
#define MAIN_UTILS_H

#include "transformations.h"

void write_image(std::ofstream &os, scene &s);

void write_color(std::ostream &out, const color &pixel_color);

#endif //MAIN_UTILS_H
