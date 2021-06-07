#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
template <typename T = long long, T identity = lim<T>::max(), const T& (*combine)(const T&, const T&) = min> struct bit2D {
    const int n, m;
    vector<vector<T>> t;
    bit2D(int n, int m) : n(n), m(m), t(n + 1, vector<T>(m + 1, identity)) {}
    void add(int r, int c, T value) {
       for(int i = r; i <= n; i += i & -i) {
            for(int j = c; j <= m; j += j & -j) {
                t[i][j] = combine(t[i][j], value);
            }
        }
    }
    T sum(int r, int c) {
        T res = identity;
        for(int i = r; i > 0; i -= i & -i) {
           for(int j = c; j > 0; j -= j & -j) {
               res = combine(res, t[i][j]);
           }
        }
        return res;
    }
};