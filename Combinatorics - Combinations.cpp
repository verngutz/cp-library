#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Permutations.cpp"
modint C(int n, int k) {
    return fact(n) * fact_inv(k) * fact_inv(n - k);
}
#endif
