#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Can> T bsearch(T L, T R, Can&& can, bool left_feasible = true) {
    static_assert(is_convertible<decltype(can), function<bool(T)>>::value, "can must be bool(T)");
    T& feasible = left_feasible ? L : R;
    T& infeasible = left_feasible ? R : L;
    for(int i = 0; i < 100; i++) {
        T M = L + (R - L) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
