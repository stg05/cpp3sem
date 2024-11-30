//
// Created by stg05 on 28.09.2024.
//

#define COMP_PRECISION 0.00001

#include "color.h"
#include <limits>

#ifndef MAIN_RAY_H
#define MAIN_RAY_H

class ray
{
public:
    ray() = default;

    ray(vec3 dir);

    ray(vec3 pivot, vec3 dir);

    vec3 at(double t);

    [[nodiscard]] vec3 get_pivot() const;

    [[nodiscard]] vec3 get_dir() const;

private:
    vec3 m_pivot{0, 0, 0}, m_dir{0, 0, 0};
};

class hit_record
{
public:
    hit_record() = default;

    void set_face_normal(const ray &, const vec3 &outward_normal);

    [[nodiscard]] vec3 normal() const;

private:
    vec3 m_intersection;
    vec3 m_normal;
    double t{0};
    bool m_front_face = false;
};

class interval
{
public:
    static const double inline INF = std::numeric_limits<double>::infinity();

private:
    double m_min, m_max;

public:
    interval() = default;
    interval(double, double);
    bool operator()(double);
};

#endif // MAIN_RAY_H