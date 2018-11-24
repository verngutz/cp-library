#include <bits/stdc++.h>
#include "Geometry - Vectors.cpp"
using namespace std;
template <typename T>
struct line2D {
    vec2D<T> point, dir;
    line2D() {}
    line2D(const vec2D<T>& p1, const vec2D<T>& p2) : point(p1), dir(p2 - p1) {}
};
template <typename T>
bool point_on_line(const vec2D<T>& point, const line2D<T>& line) {
    return (point - line.point) * line.dir == 0;
}
template <typename T>
bool coinciding(const line2D<T>& l1, const line2D<T>& l2) {
    return l1.dir * l2.dir == 0 and point_on_line(l1.point, l2);
}
template <typename T>
bool intersects(const line2D<T>& l1, const line2D<T>& l2) {
    return l1.dir * l2.dir != 0 or coinciding(l1, l2);
}
template <typename T>
vec2D<T> intersection(const line2D<T>& l1, const line2D<T>& l2) {
    return (l2.point - l1.point).vector_project(l1.dir) - l1.point;
}
