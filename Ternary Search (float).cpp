#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
template <typename Range, typename Function>
double tsearch(double L, double R, const Function& f, bool concave_up = true) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<Range(double)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "tsearch 'f' must be Range(double)");
#endif
    for(int i = 0; i < 1000; i++) {
        double M1 = (2 * L + R) / 3;
        double M2 = (L + 2 * R) / 3;
        (concave_up ? f(M1) < f(M2) : f(M1) > f(M2)) ? R = M2 : L = M1;
    }
    return (concave_up ? f(L) < f(R) : f(L) > f(R)) ? L : R;
}
