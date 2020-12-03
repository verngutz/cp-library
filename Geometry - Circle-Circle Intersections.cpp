#include "Geometry - Vectors.cpp"
#include "Geometry - Circles.cpp"
#include "Binary Search the Answer (int).cpp"
vector<vec2D<double>> intersections(const circle<double>& c1, const circle<double>& c2) {
    double centers_dist = (c2.c - c1.c).squared_norm();
    double dr = c1.r - c2.r, sr = c1.r + c2.r;
    if(dr * dr < centers_dist and centers_dist < sr * sr) {
        vec2D<double> v = (c2.c - c1.c).normalized() * c1.r;
        double theta = bsearch(0.0, M_PI, [&](double theta) { return (c2.c - (c1.c + v.rotate(theta))).norm() <= c2.r; });
        return {c1.c + v.rotate(theta), c1.c + v.rotate(-theta)};
    } else {
        return {};
    }
}
