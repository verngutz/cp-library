#include <bits/stdc++.h>
#include "Geometry - Vectors.cpp"
#include "Geometry - Segments.cpp"
using namespace std;
template <typename T>
struct poly {
    vector<vec2D<T>> vertices;
    vector<segment2D<T>> edges;
    poly(const vector<vec2D<T>>& vertices) : vertices(vertices) {
        for(int i = 0; i < vertices.size(); i++) {
            edges[i] = {vertices[i], vertices[(i + 1) % vertices.size()]};
        }
    }
};
