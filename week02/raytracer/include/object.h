//
// Created by stg05 on 05.10.2024.
//
#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "ray.h"

/** General passive object included in scene \n
 * e.g: refractors, mat objects, mirrors */
class object {
public:
    object() = default;

    virtual ~object() = default;

    [[nodiscard]] virtual bool
    hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &record) const = 0;
};

class sphere : public object {
public:
    sphere(double, double, double, double);

    sphere(vec3, double);

    [[nodiscard]] bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &record) const override;

private:
    vec3 m_center{0, 0, 0};
    double m_r = 1.;
};

#endif //MAIN_OBJECT_H