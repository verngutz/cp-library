#include <bits/stdc++.h>
#include "Data Structs - BIT (1D).cpp"
using namespace std;
// NOTE: one-indexed
template <typename T> struct range_bit {
    bit<T> t;
    range_bit(int n) : t(bit<T>(n)) {}
    void add(int L, int R, T value) {
        t.add(L, value);
        t.add(R + 1, -value);
    }
    T get(int i) {
        return t.sum(i);
    }
};
