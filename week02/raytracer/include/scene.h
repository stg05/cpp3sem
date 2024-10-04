//
// Created by stg05 on 28.09.2024.
//

#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include "viewport.h"
#include "object.h"

class scene {
public:
    scene();

    viewport v{vec3{1, 0, 0} * 0.05};

    int width() const;

    int height() const;

    ray cds_to_ray(unsigned x, unsigned y) const;

    color background(const ray &r) const;

private:
    int m_width, m_height;
};

#endif //MAIN_SCENE_H