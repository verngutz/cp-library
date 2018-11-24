#ifndef __VEC2D_INCLUDED_
#define __VEC2D_INCLUDED_
#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct vec2D {
    T x, y;
    vec2D(T x, T y) : x(x), y(y) {}
    bool operator==(const vec2D& v) const { return x == v.x and y == v.yl; }
    bool operator!=(const vec2D& v) const { return not (*this == v); }
    bool operator< (const vec2D& v) const { return x < v.x or (x == v.x and y < v.y); }
    bool operator<=(const vec2D& v) const { return *this < v or *this == v; }
    bool operator> (const vec2D& v) const { return not (*this <= v); }
    bool operator>=(const vec2D& v) const { return *this > v or *this == v; }
    vec2D operator*(const T c) const { return {c * x, c * y}; }
    vec2D operator/(const T c) const { return {x / c, y / c}; }
    vec2D operator+(const vec2D& v) const { return {x + v.x, y + v.y}; }
    vec2D operator-() const { return {-x, -y}; }
    vec2D operator-(const vec2D& v) const { return *this + -v; }
    T operator*(const vec2D& v) const { return x * v.y - y * v.x; } // cross product
    T operator^(const vec2D& v) const { return x * v.x + y * v.y; } // dot product
    vec2D& operator=(const vec2D& v) { x = v.x, y = v.y; return *this; }
    vec2D& operator*=(const T c) { return *this = *this * c; }
    vec2D& operator/=(const T c) { return *this = *this / c; }
    vec2D& operator+=(const vec2D& v) { return *this = *this + v; }
    vec2D& operator-=(const vec2D& v) { return *this = *this - v; }
    T squared_norm() { return *this ^ *this; }
    double norm() { return sqrt(squared_norm()); }
    vec2D normalized() { return *this / norm(); }
    double scalar_project(const vec2D& v) {
        return *this ^ v / v.norm();
    }
    vec2D vector_project(const vec2D& v) {
        return (*this ^ v) / (v ^ v) * v;
    }
    vec2D rotate(T theta) {
        return {cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y};
    }
};
template <typename T>
vec2D<T> operator*(const T c, const vec2D<T>& v) { return {c * v.x, c * v.y}; }
template <typename T>
ostream& operator<<(ostream& os, const vec2D<T>& v) { return os << "(" << v.x << ", " << v.y << ")"; }
template <typename T>
istream& operator>>(istream& is, vec2D<T>& v) { return is >> v.x >> v.y; }
#endif
