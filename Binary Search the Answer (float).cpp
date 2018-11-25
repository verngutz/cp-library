#include <bits/stdc++.h>
using namespace std;
double bsearch(double L, double R, const function<bool(double)>& can, bool left_feasible = true) {
    double& feasible = left_feasible ? L : R;
    double& infeasible = left_feasible ? R : L;
    for(int i = 0; i < 100; i++) {
        double M = (L + R) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
