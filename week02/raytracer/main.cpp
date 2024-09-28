#include <iostream>
#include <string>
#include <fstream>
#include "include/utils.h"



int main() {
    std::string path("my_image.ppm");
    std::ofstream os(path);
    scene s;
    write_image(os, s);
    return 0;
}
