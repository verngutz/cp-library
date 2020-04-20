#include <bits/stdc++.h>
#include "Data Structs - BIT (2D).cpp"
using namespace std;
// NOTE: one-indexed
template <typename T = long long> struct range_bit2D {
    bit2D<T> t;
    range_bit2D(int n, int m) : t(bit2D<T>(n, m)) {}
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
