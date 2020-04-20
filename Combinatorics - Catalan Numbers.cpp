#include "Combinatorics - Permutations.cpp"
template <typename T = mint> T cat(int n) {
    return fact<T>(2 * n) * fact_inv<T>(n + 1) * fact_inv<T>(n);
}
