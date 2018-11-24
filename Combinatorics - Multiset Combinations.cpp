#ifndef __MULTISET_COMBINATIONS_INCLUDED_
#define __MULTISET_COMBINATIONS_INCLUDED_
#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Integer Compositions.cpp"
modint multi_C(int n, int k) {
    return C_nonnegative(k, n);
}
#endif
