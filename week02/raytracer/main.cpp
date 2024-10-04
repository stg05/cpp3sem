#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "include/utils.h"


int main() {
    unsigned cnt = 1;
    for (double i = 5.0; i > 0.5; i /= 1.05) {
        std::string path("out\\f" + std::to_string(cnt) + ".ppm");
        cnt++;
        std::ofstream os(path);
        scene s;
        s.v = viewport{vec3{1, 0, 0} * i};
        write_image(os, s);
    }
    for (double alpha = 0; alpha <= M_PI / 2; alpha += M_PI / 60) {
        std::string path("out\\f" + std::to_string(cnt) + ".ppm");
        cnt++;
        std::ofstream os(path);
        scene s;
        s.v = viewport{vec3{cos(alpha), 0, -sin(alpha)} * 0.5};
        write_image(os, s);
    }
    for (double i = 0.5; i < 5.0; i *= 1.05) {
        std::string path("out\\f" + std::to_string(cnt) + ".ppm");
        cnt++;
        std::ofstream os(path);
        scene s;
        s.v = viewport{vec3{0, 0, -1} * i};
        write_image(os, s);
    }
    return 0;
}
