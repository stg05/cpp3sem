//
// Created by stg05 on 29.09.2024.
//

#ifndef MAIN_COLOR_H
#define MAIN_COLOR_H

#include "vec3.h"

using color = vec3;

std::string print_color(color param);

namespace colors {
    const inline color BLACK{0., 0., 0.};
    const inline color WHITE{1., 1., 1.};
    const inline color RED{1., 0., 0.};
    const inline color GREEN{0., 1., 0.};
    const inline color BLUE{0., 0., 1.};
}

#endif //MAIN_COLOR_H