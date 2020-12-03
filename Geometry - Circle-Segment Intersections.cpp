#include "Geometry - Circles.cpp"
#include "Geometry - Segments.cpp"
template <typename T> bool has_intersection(const circle<T>& c, const segment2D<T>& s) {
    return s.squared_distance(c.c) < c.r * c.r;
}
