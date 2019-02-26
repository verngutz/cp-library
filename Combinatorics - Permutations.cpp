#ifndef __PERMUTATIONS_INCLUDED_
#define __PERMUTATIONS_INCLUDED_
#include "Math - Modular Arithmetic.cpp"
modint fact(int n) {
    static vector<modint> fac = {1};
    while(fac.size() <= n) {
        fac.push_back(fac.back() * int(fac.size()));
    }
    return fac[n];
}
modint fact_inv(int n) {
    static vector<modint> inv_fac = {1};
    while(inv_fac.size() <= n) {
        inv_fac.push_back(inv_fac.back() / int(inv_fac.size()));
    }
    return inv_fac[n];
}
#endif
