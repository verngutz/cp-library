#include <bits/stdc++.h>
#include "Data Structs - BIT (2D).cpp"
using namespace std;
// NOTE: one-indexed, don't forget to declare static inside main
template <typename T, int N, int M>
// template <typename T = long long, int N = 1000, int M = 1000>
struct range_bit2D {
    bit2D<T, N, M> t;
    void r_add(int r1, int c1, int r2, int c2, T value) {
        t.add(r1, c1, value);
        t.add(r1, c2 + 1, -value);
        t.add(r2 + 1, c1, -value);
        t.add(r2 + 1, c2 + 1, value);
    }
    T get(int r, int c) {
        return t.sum(r, c);
    }
};
