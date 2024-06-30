#include "Combinatorics - Combinations.cpp"
mint k_simplex(int n, int k) {
    return C(n + k - 1, k);
}
mint sk_simplex(int n, int k) {
    return k_simplex(n, k + 1);
}