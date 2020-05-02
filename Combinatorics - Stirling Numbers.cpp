#include "Combinatorics - Combinations.cpp"
template <typename T = mint> T S(int n, int k) {
    T ans = 0;
    for(int i = 0, sgn = 1; i <= k; i++, sgn = -sgn) {
        ans += sgn * C(k, i) * (T(k - i) ^ n);
    }
    return ans / fact(k);
}