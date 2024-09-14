#include <iostream>
#include <string>
#include <fstream>
#include "include/utils.h"



int main() {
    std::string path("my_image.ppm");
    std::ofstream os(path);
    write_image(os);

    return 0;
}
