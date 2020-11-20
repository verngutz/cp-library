#include "Geometry - Vectors.cpp"
#include "Binary Search the Answer (int).cpp"
vector<vec2D<double>> intersections(const vec2D<double>& c1, double r1, const vec2D<double>& c2, double r2) {
    if(max(r1, r2) - min(r1, r2) <= (c2 - c1).norm() and (c2 - c1).norm() <= r1 + r2) {
        vec2D<double> v = (c2 - c1).normalized() * r1;
        double theta = bsearch(0.0, M_PI, [&](double theta) { return (c2 - (c1 + v.rotate(theta))).norm() <= r2; });
        return {c1 + v.rotate(theta), c1 + v.rotate(-theta)};
    } else {
        return {};
    }
}