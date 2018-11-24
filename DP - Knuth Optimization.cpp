#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
// argmin opt(i, k) + opt(k + 1, j - 1) + c(i, j - 1)
// <= argmin opt(i, k) + opt(k + 1, j) + c(i, j)
// <= argmin opt(i + 1, k) + opt(k + 1, j) + c(i + 1, j)
// must be satisfied
// alternatively, c must satisfy for all a <= b <= c <= d:
// quadrangle inequality: c(a, c) + c(b, d) <= c(a, d) + c(b, c)
// monotonicity: c(b, c) <= c(a, d)
template<typename T, size_t N, typename Function>
T knuth(int n, const Function& c) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<T(int, int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "knuth 'c' must be T(int, int)");
#endif
    static T opt[N+2][N+2];
    static int optk[N+2][N+2];
    memset(opt, 0, sizeof opt);
    for(int len = 1; len <= n; len++) {
        for(int i = 1, j; (j = i + len - 1) <= n; i++) {
            if(len == 1) {
                opt[i][j] = c(i, j), optk[i][j] = i;
            } else {
                for(int k = optk[i][j-1]; k <= optk[i+1][j]; k++) {
                    T cur = opt[i][k] + opt[k+1][j] + c(i, j);
                    if(k == optk[i][j-1] or opt[i][j] > cur) {
                        opt[i][j] = cur;
                        optk[i][j] = k;
                    }
                }
            }
        }
    }
    return opt[1][n];
}
