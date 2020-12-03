#include <bits/stdc++.h>
#include "Geometry - Vectors.cpp"
using namespace std;
template <typename T> struct circle {
    vec2D<T> c;
    T r;
    friend ostream& operator<<(ostream& os, const circle<T>& c) { return os << "[" << c.c << ", " << c.r << "]"; }
    friend istream& operator>>(istream& is, circle<T>& c) { return is >> c.c >> c.r; }
};
