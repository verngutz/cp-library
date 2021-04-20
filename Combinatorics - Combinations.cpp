#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#include "Combinatorics - Permutations.cpp"
template <typename T = mint> T C(int n, int k) {
    assert(n >= 0), assert(k >= 0);
    return k <= n ? fact<T>(n) * fact_inv<T>(k) * fact_inv<T>(n - k) : 0;
}
template <typename T = mint> T C(ll n, int k) {
    T ans = 1;
    while(n > 0 or k > 0) {
        ans *= C<T>(int(n % T::M), k % T::M);
        n /= T::M;
        k /= T::M;
    }
    return ans;
}
#endif
