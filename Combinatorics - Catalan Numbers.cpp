#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Permutations.cpp"
modint cat(int n) {
    return f(2 * n) * f_inv(n + 1) * f_inv(n);
}
