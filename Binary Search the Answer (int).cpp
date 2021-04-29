#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Can> T bsearch(T L, T R, const Can& can, bool left_feasible = true) {
    static_assert(is_convertible<decltype(can), function<bool(T)>>::value);
    T& feasible = left_feasible ? L : R;
    T& infeasible = left_feasible ? R : L;
    while(R - L > 1) {
        T M = L + (R - L) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
