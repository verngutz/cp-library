#include <bits/stdc++.h>
#include "Misc - Lg.cpp"
using namespace std;
template <typename T> struct sparse_table {
    const int size;
    const T zero;
    const function<T(T, T)> combine;
    vector<vector<T>> st;
    sparse_table(const vector<T>& a, T zero, const function<T(T, T)>& combine)
    : size(a.size()), zero(zero), combine(combine), st(lg(size) + 1, vector<T>(size, zero)) {
        for(int pow2 = 0; pow2 <= lg(size); pow2++) {
            for(int i = 0; i + (1 << pow2) - 1 < size; i++) {
                st[pow2][i] = pow2 ? combine(st[pow2 - 1][i], st[pow2 - 1][i + (1 << (pow2 - 1))]) : a[i];
            }
        }
    }
    T query(int L, int R, bool inclusive) {
        assert(L < R + inclusive);
        R += inclusive;
        return combine(st[lg(R - L)][L], st[lg(R - L)][R - (1 << lg(R - L))]);
    }
};
