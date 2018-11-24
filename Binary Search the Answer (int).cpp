#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
template <typename T, typename Function>
T bsearch(T L, T R, const Function& can, bool left_feasible = true) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<bool(T)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "bsearch 'can' must be bool(T)");
#endif
    T& feasible = left_feasible ? L : R;
    T& infeasible = left_feasible ? R : L;
    while(R - L > 1) {
        T M = (L + R) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
