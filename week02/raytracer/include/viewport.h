// Created by stg05 on 28.09.2024.
//

#include "ray.h"

#ifndef MAIN_VIEWPORT_H
#define MAIN_VIEWPORT_H

class viewport {

public:
    viewport();

    explicit viewport(vec3 focal_vec);

    vec3 get_center() const;

    vec3 get_u() const;

    vec3 get_v() const;

private:
    double m_width, m_height;
    vec3 center = {0, 0, -1};
    vec3 m_u = {1, 0, 0},
            m_v = {0, -1, 0};
};

class rectangular_viewport : public viewport {

};

class spherical_viewport : public viewport {

};

#endif //MAIN_VIEWPORT_H