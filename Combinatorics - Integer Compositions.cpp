#include "Combinatorics - Combinations.cpp"
template <typename T = mint> T C_nonnegative(int n, int k) {
    return k == 0 ? n == 0 : C<T>(n + k - 1, k - 1);
}
template <typename T = mint> T C_nonnegative(int n, int k, int ub) {
    T ans = C_nonnegative<T>(n, k);
    T sgn = -1;
    for(int i = 1; i <= k and n - ub * i >= 0; i++) {
        ans += sgn * C<T>(k, i) * C_nonnegative<T>(n - ub * i, k);
        sgn *= -1;
    }
    return ans;
}
template <typename T = mint> T C_positive(int n, int k) {
    return C_nonnegative(n - k, k);
}
template <typename T = mint> T C_positive(int n) {
    return n == 0 ? 1 : T(2) ^ (n - 1);
}
