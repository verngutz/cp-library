#include <bits/stdc++.h>
#include "Data Structs - Monoid.cpp"
using namespace std;
template <typename T> struct sparse_table {
    const int size;
    const monoid<T> m;
    vector<vector<T>> st;
    sparse_table(const vector<T>& a, const monoid<T>& m)
    : size(a.size()), m(m), st(__lg(size) + 1, vector<T>(size, m.identity)) {
        for(int pow2 = 0; pow2 <= __lg(size); pow2++) {
            for(int i = 0; i + (1 << pow2) - 1 < size; i++) {
                st[pow2][i] = pow2 ? m.combine(st[pow2 - 1][i], st[pow2 - 1][i + (1 << (pow2 - 1))]) : a[i];
            }
        }
    }
    T query(int L, int R, bool inclusive) {
        assert(L < R + inclusive);
        R += inclusive;
        return m.combine(st[__lg(R - L)][L], st[__lg(R - L)][R - (1 << __lg(R - L))]);
    }
};
