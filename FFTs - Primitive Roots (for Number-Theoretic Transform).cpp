#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 998244353;
#include "Math - Modular Arithmetic.cpp"
#include "Number Theory - Factorization O(sqrt n).cpp"
modint primitive_root(ll n) {
    vector<ll> factors;
    factorize<ll>(n - 1, [](ll){}, [&](ll p) { factors.push_back(p); });
    for(modint a = 2; a < n; a++) {
        bool is_primitive_root = true;
        for(auto f : factors) {
            is_primitive_root &= (a ^ ((n - 1) / f)) != 1;
        }
        if(is_primitive_root) {
            return a;
        }
    }
}
const modint R = primitive_root(M);
const ll K = (M - 1) & -(M - 1);
const modint W = R ^ ((M - 1) / K);
modint w(int len, bool inverse) {
    return ((inverse ? ~W : W) ^ (K / len));
}
