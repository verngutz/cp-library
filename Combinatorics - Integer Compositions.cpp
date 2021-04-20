#include "Combinatorics - Combinations.cpp"
template <typename Out = mint, typename In = int> Out C_nonnegative(In n, int k) {
    return k == 0 ? n == 0 : C<Out>(n + k - 1, k - 1);
}
template <typename Out = mint, typename In = int> Out C_nonnegative(In n, int k, int ub) {
    Out ans = C_nonnegative<Out, In>(n, k);
    int sgn = -1;
    for(int i = 1; i <= k and n - ub * i >= 0; i++) {
        ans += sgn * C<Out>(k, i) * C_nonnegative<Out, In>(n - ub * i, k);
        sgn *= -1;
    }
    return ans;
}
template <typename Out = mint, typename In = int> Out C_positive(In n, int k) {
    return C_nonnegative<Out, In>(n - k, k);
}
template <typename Out = mint, typename In = int> Out C_positive(In n) {
    return n == 0 ? 1 : Out(2) ^ (n - 1);
}
