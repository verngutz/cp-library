#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
#define N 1000
bool a[N+2][N+2] = {};
bool vis[N+2][N+2] = {};
bool hori(int di, int dj) { return abs(di) == 0 and abs(dj) == 1; }
bool vert(int di, int dj) { return abs(di) == 1 and abs(dj) == 0; }
bool diag(int di, int dj) { return abs(di) == 1 and abs(dj) == 1; }
bool can(int di, int dj) { return hori(di, dj) or vert(di, dj) or diag(di, dj); }
template <typename CanFunction, typename FloodFunction>
int flood(int i, int j, const CanFunction& can, const FloodFunction& f) {
#ifdef DEBUG
    using f_actual_type = typename callable_traits<FloodFunction>::function_type;
    using f_expected_type = typename callable_traits<void(int, int)>::function_type;
    static_assert(is_same<f_actual_type, f_expected_type>::value, "flood 'f' must be void(int, int)");
    using can_actual_type = typename callable_traits<CanFunction>::function_type;
    using can_expected_type = typename callable_traits<bool(int, int)>::function_type;
    static_assert(is_same<can_actual_type, can_expected_type>::value, "flood 'can' must be bool(int, int)");
#endif
    if(a[i][j] and not vis[i][j]) {
        f(i, j);
        vis[i][j] = true;
        int ans = 1;
        for(int di = -1; di <= 1; di++) {
            for(int dj = -1; dj <= 1; dj++) {
                if(can(di, dj)) {
                    ans += flood(i + di, j + dj, f);
                }
            }
        }
        return ans;
    }
    return 0;
}
template <typename CanFunction>
int flood(int i, int j, const CanFunction& can) { return flood(i, j, can, [](int i, int j) {}); }
void block_boundaries(int n, int m) {
    for(int i = 0; i <= n + 1; i++) {
        a[i][0] = false;
        a[i][m + 1] = false;
    }
    for(int i = 0; i <= m + 1; i++) {
        a[0][i] = false;
        a[n + 1][i] = false;
    }
}
