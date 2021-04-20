#include "Combinatorics - Combinations.cpp"
template <typename Out = mint, typename In = int> Out k_simplex(In n, int k) {
    return C<Out>(n + k - 1, k);
}
template <typename Out = mint, typename In = int> Out sk_simplex(In n, int k) {
    return k_simplex<Out, In>(n, k + 1);
}
