#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
template <typename T = long long> struct bit2D {
    const int n, m;
    vector<vector<T>> t;
    bit2D(int n, int m) : n(n), m(m), t(n, vector<T>(m)) {}
    void add(int r, int c, T value) {
       for(int i = r; i <= n; i += i & -i) {
            for(int j = c; j <= m; j += j & -j) {
                t[i][j] += value;
            }
        }
    }
    T sum(int r, int c) {
        T res = 0;
        for(int i = r; i > 0; i -= i & -i) {
           for(int j = c; j > 0; j -= j & -j) {
               res += t[i][j];
           }
        }
        return res;
    }
    T sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }
};
