#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Combinations.cpp"
modint C_positive(int n, int k) {
    return n == 0 ? 1 : C(n - 1, k - 1);
}
modint C_positive(int n) {
    return n == 0 ? 1 : modint(2) ^ (n - 1);
}
modint C_nonnegative(int n, int k) {
    return C(n + k - 1, k - 1);
}
