#ifndef __PERMUTATIONS_INCLUDED_
#define __PERMUTATIONS_INCLUDED_
#include "Math - Modular Arithmetic.cpp"
modint f(int n) {
    static vector<modint> fac = {1};
    while(fac.size() <= n) {
        fac.push_back(fac.back() * fac.size());
    }
    return fac[n];
}
modint f_inv(int n) {
    static vector<modint> inv_fac = {1};
    while(inv_fac.size() <= n) {
        inv_fac.push_back(inv_fac.back() / inv_fac.size());
    }
    return inv_fac[n];
}
#endif
