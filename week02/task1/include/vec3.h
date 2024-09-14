//
// Created by stg05 on 14.09.2024.
//

#include <string>


#ifndef MAIN_VEC3_H
#define MAIN_VEC3_H

#endif //MAIN_VEC3_H

class vec3 {
public:
    vec3() = default;

    vec3(double x, double y, double z);

    double x() const;

    double y() const;

    double z() const;

    double get(unsigned idx) const;

    void add(const vec3 &param);

    void sub(const vec3 &param);

    void scale(double factor);

    double dot(const vec3 &param) const;

    vec3 cross(const vec3 &param) const;

    std::string print() const;

    double length() const;

    double length_squared() const;

    vec3 operator+(const vec3 &param) const;

    vec3 operator-(const vec3 &param) const;

    vec3 operator-() const;

    double operator*(const vec3 &param) const;

    vec3 operator^(const vec3 &param) const;

private:
    double m_x{0}, m_y{0}, m_z{0};
};

using color = vec3;

std::string print_color(color param);

vec3 operator*(double alpha, vec3 param);