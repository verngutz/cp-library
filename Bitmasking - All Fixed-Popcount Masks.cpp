#include <bits/stdc++.h>
#include "Bitmasking - Bitmask Next Permutation (128-bit).cpp"
#include "Bitmasking - Bitmask Next Permutation.cpp"
using namespace std;
template <typename T, typename F> void for_each_subset(int n, int k, F&& f) {
    static_assert(is_convertible<decltype(f), function<void(T)>>::value);
    for(T mask = (T(1) << k) - 1; mask <= (T(1) << k) - 1 << n - k; mask = next_permutation(mask)) {
        f(mask);
    }
}
