#include <bits/stdc++.h>
#include "Geometry - Vectors.cpp"
using namespace std;
template <typename T> struct line2D {
    vec2D<T> point, dir;
    line2D() {}
    line2D(const vec2D<T>& p1, const vec2D<T>& p2) : point(p1), dir(p2 - p1) {}
    T a() const { return -dir.y; }
    T b() const { return dir.x; }
    T c() const { return dir * point; }
    T turn(const vec2D<T>& p) const { return dir * (p - point); }
    bool contains(const vec2D<T>& p) const { return turn(p) == 0; }
    double distance(const vec2D<T>& p) const { return abs(turn(p)) / dir.norm(); }
    T squared_distance(const vec2D<T>& p) const { return turn(p) * turn(p) / dir.squared_norm(); }
    line2D perp(const vec2D<T>& p) const { return {p, p + dir.perp()}; }
    bool operator==(const line2D& l) const { return dir * l.dir == 0 and contains(l.point); };
    bool operator!=(const line2D& l) const { return not (*this == l); }
    bool intersects(const line2D& l) const { return dir * l.dir != 0 or *this == l; };
    vec2D<T> intersection(const line2D& l) const { return (c() * l.dir - l.c() * dir) / (dir * l.dir); }
};
