#include <bits/stdc++.h>
#include "Convolutions (Bitwise) - Mobius Transform.cpp"
using namespace std;
template <typename T> vector<T> subset_convolution(const vector<T>& a, const vector<T>& b) {
    int n = __lg(a.size());
    vector<vector<T>> c(n + 1, vector<T>(1 << n));
    vector<vector<T>> trunc_a(n + 1, vector<T>(a.size()));
    vector<vector<T>> trunc_b(n + 1, vector<T>(b.size()));
    for(int mask = 0; mask < (1 << n); mask++) {
        trunc_a[__builtin_popcount(mask)][mask] = a[mask];
        trunc_b[__builtin_popcount(mask)][mask] = b[mask];
    }
    for_each(trunc_a.begin(), trunc_a.end(), zeta<T>);
    for_each(trunc_b.begin(), trunc_b.end(), zeta<T>);
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                c[i][mask] += trunc_a[j][mask] * trunc_b[i - j][mask];
            }
        }
    }
    for_each(c.begin(), c.end(), mu<T>);
    vector<T> ans(1 << n);
    for(int mask = 0; mask < ans.size(); mask++) {
        ans[mask] = c[__builtin_popcount(mask)][mask];
    }
    return ans;
}
