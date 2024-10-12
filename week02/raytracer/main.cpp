#include <iostream>
#include <cmath>
#include "include/utils.h"


int main() {
    sequence_renderer seq_ren;
    scene s;
    auto *sph = new sphere{0, 0, -5, 4.5};
    auto *sph2 = new sphere{0, -20.1, 0, 20};
    s.objects.push_front(sph);
    s.objects.push_front(sph2);
    s.v = viewport(vec3{0, 0, -1});
    seq_ren.render_frame(s);
    delete sph;
    delete sph2;
//    for (double i = 5.0; i > 0.5; i /= 1.05) {
//        s.v = viewport{vec3{1, 0, 0} * i};
//        seq_ren.render_frame(s);
//    }
//    for (double alpha = 0; alpha <= M_PI/ 2; alpha += M_PI / 60) {
//        s.v = viewport{vec3{cos(alpha), 0, -sin(alpha)} * 0.5};
//        seq_ren.render_frame(s);
//    }
//    for (double i = 0.5; i < 5.0; i *= 1.05) {
//        s.v = viewport{vec3{0, 0, -1} * i};
//        seq_ren.render_frame(s);
//    }
    return 0;
}
