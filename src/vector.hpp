#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

struct Vector {
    double x = 0, y = 0, z = 0;

    Vector() = default;
    Vector(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    Vector operator+(const Vector& o) const {
        return {x + o.x, y + o.y, z + o.z};
    }
    Vector operator-(const Vector& o) const {
        return {x - o.x, y - o.y, z - o.z};
    }
    Vector operator*(double s) const {
        return {x * s, y * s, z * s};
    }
    Vector& operator+=(const Vector& o) {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
    Vector& operator*=(double s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    double normSq() const {
        return x * x + y * y + z * z;
    }
    double norm() const {
        return std::sqrt(normSq());
    }
};
#endif