//
// Created by stg05 on 28.09.2024.
//

#include "viewport.h"

#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#endif //MAIN_SCENE_H

class scene {
public:
    scene();

    viewport v{{0, 1, -1}};

    int width() const;

    int height() const;

    ray cds_to_ray(unsigned x, unsigned y) const;

private:
    int m_width, m_height;
};
