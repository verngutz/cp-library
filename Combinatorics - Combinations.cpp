#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#include "Combinatorics - Permutations.cpp"
template <typename T = mint> T C(int n, int k) {
    return fact<T>(n) * fact_inv<T>(k) * fact_inv<T>(n - k);
}
#endif
