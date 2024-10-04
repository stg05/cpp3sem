//
// Created by stg05 on 05.10.2024.
//

#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "ray.h"

class object {
public:
    virtual ~object() = default;

    [[nodiscard]] virtual bool intersects_ray(const ray &r) const = 0;
};

class sphere : public object {
public:
    sphere(double, double, double, double);

    sphere(vec3, double);

    [[nodiscard]] bool intersects_ray(const ray &r) const override;

private:
    vec3 m_center{0, 0, 0};
    double m_r = 1.;
};

#endif //MAIN_OBJECT_H