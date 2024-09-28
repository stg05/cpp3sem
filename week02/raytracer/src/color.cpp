//
// Created by stg05 on 29.09.2024.
//

#include "../include/color.h"

std::string print_color(color param) {
    return std::to_string(int(param.x() * 255.999)) + " " +
           std::to_string(int(param.y() * 255.999)) + " " +
           std::to_string(int(param.z() * 255.999));
}