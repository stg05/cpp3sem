//
// Created by stg05 on 28.09.2024.
//

#include "../include/ray.h"


ray::ray(vec3 pivot, vec3 dir) : m_dir{dir}, m_pivot{pivot} {}

vec3 ray::at(double t) { return vec3{m_pivot + m_dir * t}; }

vec3 ray::get_pivot() const { return m_pivot; }

vec3 ray::get_dir() const { return m_dir; }

ray::ray(vec3 dir) : m_dir{dir} {}

void hit_record::set_face_normal(const ray &r, const vec3 &outward_normal) {
    m_normal = outward_normal;
    m_front_face = r.get_dir() * outward_normal < 0;
}

vec3 hit_record::normal() const {
    return m_normal;
}
