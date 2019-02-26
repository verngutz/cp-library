#include "Math - Modular Arithmetic.cpp"
modint primitive_root(ll n) {
    set_M(n);
    vector<ll> prime_factors;
    factorize<ll>(PHI_M, [](ll){}, [&](ll p) { prime_factors.push_back(p); });
    for(modint a = 2; a <= n - 1; a++) {
        bool is_primitive_root = true;
        for(auto p : prime_factors) {
            is_primitive_root &= (a ^ (PHI_M / p)) != 1;
        }
        if(is_primitive_root) {
            return a;
        }
    }
    return 0;
}
