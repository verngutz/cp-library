#include <bits/stdc++.h>
using namespace std;
template <typename T> T bsearch(T L, T R, const function<bool(T)>& can, bool left_feasible = true) {
    T& feasible = left_feasible ? L : R;
    T& infeasible = left_feasible ? R : L;
    while(R - L > 1) {
        T M = L + (R - L) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
