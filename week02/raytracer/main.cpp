#include <iostream>
#include <cmath>
#include "include/utils.h"

int main()
{
    sequence_renderer v;
    scene s;
    sphere sph{10, 0, 0, 2};
    sphere sph2{0, 0, -10, 2};
    s.objects.push_front(&sph);
    s.objects.push_front(&sph2);
    for (double i = 5.0; i > 0.5; i /= 1.05)
    {
        s.v = viewport{vec3{1, 0, 0} * i};
        v.render_frame(s);
    }
    for (double alpha = 0; alpha <= M_PI / 2; alpha += M_PI / 60)
    {
        s.v = viewport{vec3{cos(alpha), 0, -sin(alpha)} * 0.5};
        v.render_frame(s);
    }
    for (double i = 0.5; i < 5.0; i *= 1.05)
    {
        s.v = viewport{vec3{0, 0, -1} * i};
        v.render_frame(s);
    }
    return 0;
}
