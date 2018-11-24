#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
template <typename Domain, typename Range, typename Function>
Domain tsearch(Domain L, Domain R, const Function& f, bool concave_up = true) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<Range(Domain)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "tsearch 'f' must be Range(Domain)");
#endif
    while(R - L > 1) {
        Domain M = (L + R) / 2;
        ((concave_up ? f(M) < f(M + 1) : f(M) > f(M + 1)) ? R : L) = M;
    }
    return (concave_up ? f(L) < f(R) : f(L) > f(R)) ? L : R;
}
