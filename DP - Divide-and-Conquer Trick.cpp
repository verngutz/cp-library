#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
// argmin opt(i, k) + c(k + 1, j) <= argmin opt(i, k) + c(k + 1, j + 1) must be satisfied
template<typename T, size_t PARTS, size_t SZ, typename Function>
T dnc(int parts, int n, const Function& c) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<T(int, int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "dnc 'c' must be T(int, int)");
#endif
    static T opt[PARTS+1][SZ+1];
    using make_row_t = function<void(int, int, int, int, int)>;
    make_row_t make_row = [&](int p, int s, int e, int ks, int ke) {
        if(s > e) return;
        int m = (s + e) / 2;
        int bestk = ks;
        for(int k = ks; k <= min(ke, m - 1); k++) {
            T cur = opt[p-1][k] + c(k + 1, m);
            if(k == ks or opt[p][m] > cur) {
                opt[p][m] = cur;
                bestk = k;
            }
        }
        make_row(p, s, m - 1, ks, bestk);
        make_row(p, m + 1, e, bestk, ke);
    };
    for(int p = 1; p <= parts; p++) {
        if(p == 1) {
            for(int i = 0; i <= n; i++) {
                opt[p][i] = c(1, i);
            }
        } else {
            make_row(p, 0, n, 0, n);
        }
    }
    return opt[parts][n];
}
