//
// Created by stg05 on 14.09.2024.
//

#include "../include/vec3.h"
#include <cmath>

vec3::vec3(double x, double y, double z) :
        m_x{x},
        m_y{y},
        m_z{z} {
}

double vec3::x() const {
    return m_x;
}

double vec3::y() const {
    return m_y;
}

double vec3::z() const {
    return m_z;
}

double vec3::get(unsigned int idx) const {
    switch (idx) {
        case 0: {
            return m_x;
            break;
        }
        case 1: {
            return m_y;
            break;
        }
        case 2: {
            return m_z;
            break;
        }
        default: {
            return 0;
        }
    }
}

void vec3::add(const vec3 &param) {
    m_x += param.x();
    m_y += param.y();
    m_z += param.z();
}

void vec3::sub(const vec3 &param) {
    m_x -= param.x();
    m_y -= param.y();
    m_z -= param.z();
}

void vec3::scale(double factor) {
    m_x *= factor;
    m_y *= factor;
    m_z *= factor;
}

double vec3::dot(const vec3 &param) const {
    double res{0};
    res += m_x * param.x();
    res += m_y * param.y();
    res += m_z * param.z();
    return res;
}

vec3 vec3::cross(const vec3 &param) const {
    vec3 res{0, 0, 0};
    res.m_z = m_x * param.m_y - m_y * param.m_x;
    res.m_y = m_z * param.m_x - m_x * param.m_z;
    res.m_x = m_y * param.m_z - m_z * param.m_y;
    return res;
}

std::string vec3::print() const {
    return "x=" + std::to_string(m_x) + "; y=" + std::to_string(m_y) + "; z=" + std::to_string(m_z) + "\n";
}

double vec3::length() const {
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double vec3::length_squared() const {
    return m_x * m_x + m_y * m_y + m_z * m_z;
}

vec3 vec3::operator+(const vec3 &param) const {
    return vec3{m_x + param.m_x, m_y + param.m_y, m_z + param.m_z};
}

vec3 vec3::operator-(vec3 const &param) const {
    return vec3{m_x - param.m_x, m_y - param.m_y, m_z - param.m_z};
}

vec3 vec3::operator-() const {
    return vec3{-m_x, -m_y, -m_z};
}

double vec3::operator*(const vec3 &param) const {
    return m_x * param.m_x + m_y * param.m_y + m_z * param.m_z;
}

vec3 vec3::operator^(const vec3 &param) const {
    return vec3{m_y * param.m_z - m_z * param.m_y,
                m_z * param.m_x - m_x * param.m_z,
                m_x * param.m_y - m_y * param.m_x};
}

std::string print_color(color param) {
    return std::to_string(int(param.x() * 255.999)) + " " +
           std::to_string(int(param.y() * 255.999)) + " " +
           std::to_string(int(param.z() * 255.999));
}

vec3 operator*(double alpha, vec3 vec) {
    return vec3{alpha * vec.x(),
                alpha * vec.y(),
                alpha * vec.z()};
}
