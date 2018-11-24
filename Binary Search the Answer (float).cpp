#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
template <typename Function>
double bsearch(double L, double R, const Function& can, bool left_feasible = true) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<bool(double)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "bsearch 'can' must be bool(double)");
#endif
    double& feasible = left_feasible ? L : R;
    double& infeasible = left_feasible ? R : L;
    for(int i = 0; i < 100; i++) {
        double M = (L + R) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
