//
// Created by stg05 on 05.10.2024.
//

#include <iostream>
#include "../include/object.h"
#include <cmath>

sphere::sphere(double x, double y, double z, double r) : object(), m_center{x, y, z}, m_r{r} {}

sphere::sphere(vec3 center, double r) : object(), m_center{center}, m_r{r} {}

bool sphere::hit(const ray &r, interval scope, hit_record &record) const
{
    vec3 delta = m_center - r.get_pivot();
    vec3 dir = r.get_dir();
    vec3 proj = (delta * dir.e()) * (dir.e());
    vec3 delta_per = delta - proj;
    bool result = (double(delta_per) < m_r);
    if (!result)
    {
        return false;
    }
    double offset_from_center = std::sqrt(m_r * m_r - delta_per.length_squared());
    vec3 intersection = proj - offset_from_center * dir.e();
    if (!scope(double(intersection)) || (intersection * dir < 0))
    {
        return false;
    }
    else
    {
        vec3 normal_vec = (intersection - m_center).e();
        record.set_face_normal(r, normal_vec);
        return true;
    }
}
