#ifndef __VEC2D_INCLUDED_
#define __VEC2D_INCLUDED_
#include <bits/stdc++.h>
using namespace std;
template <typename T> struct vec2D {
    T x, y;
    bool operator==(const vec2D& v) const { return x == v.x and y == v.y; }
    bool operator!=(const vec2D& v) const { return not (*this == v); }
    bool operator<(const vec2D& v) const { return x < v.x or (x == v.x and y < v.y); }
    vec2D& operator+=(const vec2D& v) { x += v.x, y += v.y; return *this; }
    vec2D& operator-=(const vec2D& v) { x -= v.x, y -= v.y; return *this; }
    vec2D& operator*=(const T c) { x *= c, y *= c; return *this; }
    vec2D& operator/=(const T c) { x /= c, y /= c; return *this; }
    vec2D operator+(const vec2D& v) const { return move(vec2D(*this) += v); }
    vec2D operator-(const vec2D& v) const { return move(vec2D(*this) -= v); }
    vec2D operator*(const T c) const { return move(vec2D(*this) *= c); }
    vec2D operator/(const T c) const { return move(vec2D(*this) /= c); }
    vec2D operator-() const { return {-x, -y}; }
    T operator*(const vec2D& v) const { return x * v.y - y * v.x; } // cross product
    T operator|(const vec2D& v) const { return x * v.x + y * v.y; } // dot product
    T squared_norm() const { return *this | *this; }
    double norm() const { return sqrt(squared_norm()); }
    vec2D normalized() const { return *this / norm(); }
    double scalar_project(const vec2D& v) const { return (*this|v) / v.norm(); }
    vec2D vector_project(const vec2D& v) const { return (*this|v) / (v|v) * v; }
    vec2D perp() const { return {-y, x}; }
    vec2D rotate(T t) const { return {cos(t) * x - sin(t) * y, sin(t) * x + cos(t) * y}; }
    friend vec2D operator*(const T c, const vec2D& v) { return v * c; }
    friend ostream& operator<<(ostream& os, const vec2D<T>& v) { return os << "(" << v.x << ", " << v.y << ")"; }
    friend istream& operator>>(istream& is, vec2D<T>& v) { return is >> v.x >> v.y; }
};
#endif
