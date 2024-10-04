//
// Created by stg05 on 05.10.2024.
//

#include "../include/object.h"

sphere::sphere(double x, double y, double z, double r) : m_center{x, y, z}, m_r{r} {}

sphere::sphere(vec3 center, double r) : m_center{center}, m_r{r} {}

bool sphere::intersects_ray(const ray &r) const {
    vec3 delta = m_center - r.get_pivot();
    vec3 dir = r.get_dir();
    vec3 proj = (delta * dir) * (dir.e());
    vec3 delta_per = delta - proj;
    return double(delta_per) < m_r;
}

