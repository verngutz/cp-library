#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
// all ways to form pairs so that p[0] paired with p[n-1], p[1] with p[n-1], ...
template <typename Function>
void paired_permutations(int n, const Function& f) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<void(vector<int>&)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "paired_permutations 'f' must be void(vector<int>&)");
#endif
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<void(int)> rb = [&](int i) {
        if(i == n / 2) {
            f(p);
        } else {
            for(int j = i + 1; j < n - i; j++) {
                swap(p[j], p[n - 1 - i]);
                rb(i + 1);
                swap(p[j], p[n - 1 - i]);
            }
        }
    };
    if(n % 2) {
        for(int i = 0; i < n; i++) {
            swap(p[i], p[n / 2]);
            rb(0);
            swap(p[i], p[n / 2]);
        }
    } else {
        rb(0);
    }
}
