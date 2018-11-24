#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
template <typename Function>
void all_1s(int mask, const Function& f) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<void(int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "all_1s 'f' must be void(int)");
#endif
    for(int x = mask; x - (x & -x) > 0; x -= x & -x) {
        f(__builtin_ffs(x & -x) - 1);
    }
}
template <typename Function>
void all_1_pairs(int mask, const Function& f) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<void(int, int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "all_1_pairs 'f' must be void(int, int)");
#endif
    for(int x = mask; x - (x & -x) > 0; x -= x & -x) {
        for(int y = x - (x & -x); y > 0; y -= y & -y) {
            f(__builtin_ffs(x & -x) - 1, __builtin_ffs(y & -y) - 1);
        }
    }
}
template <typename Function>
void all_1_triples(int mask, const Function& f) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<void(int, int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "all_1_triples 'f' must be void(int, int, int)");
#endif
    for(int x = mask; x - (x & -x) > 0; x -= x & -x) {
        for(int y = x - (x & -x); y - (y & -y) > 0; y -= y & -y) {
            for(int z = y - (y & -y); z > 0; z -= z & -z) {
                f(__builtin_ffs(x & -x) - 1, __builtin_ffs(y & -y) - 1, __builtin_ffs(z & -z) - 1);
            }
        }
    }
}
template <typename Function>
void all_subsets(int mask, const Function& f) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<void(int, int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "all_subsets 'f' must be void(int)");
#endif
    for(int x = mask; x > 0; x = (x - 1) & mask) {
        f(x);
    }
}
