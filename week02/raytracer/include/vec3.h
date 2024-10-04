//
// Created by stg05 on 14.09.2024.
//

#include <string>

#ifndef MAIN_VEC3_H
#define MAIN_VEC3_H

class vec3 {
public:
    vec3() = default;

    vec3(double x, double y, double z);

    [[nodiscard]] double x() const;

    [[nodiscard]] double y() const;

    [[nodiscard]] double z() const;

    [[nodiscard]] double get(unsigned idx) const;

    void add(const vec3 &param);

    void sub(const vec3 &param);

    void scale(double factor);

    [[nodiscard]] double dot(const vec3 &param) const;

    [[nodiscard]] vec3 cross(const vec3 &param) const;

    [[nodiscard]] std::string print() const;

    [[nodiscard]] double length() const;

    [[nodiscard]] double length_squared() const;

    vec3 operator+(const vec3 &param) const;

    vec3 operator-(const vec3 &param) const;

    vec3 operator-() const;

    double operator*(const vec3 &param) const;

    vec3 operator^(const vec3 &param) const;

    void operator*=(double alpha);

    [[nodiscard]] vec3 e() const;

    explicit operator double() const;

private:
    double m_x{0}, m_y{0}, m_z{0};
};


vec3 operator*(double alpha, vec3 param);

vec3 operator*(vec3 param, double alpha);

#endif //MAIN_VEC3_H