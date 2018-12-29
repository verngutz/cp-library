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
vector<modint> pad(const vector<modint>& a, int min_size) {
    while(min_size != (min_size & -min_size)) {
        min_size++;
    }
    if(min_size == a.size()) {
        return a;
    } else {
        vector<modint> padded(min_size);
        copy(a.begin(), a.end(), padded.begin());
        return padded;
    }
}
vector<modint> ntt(const vector<modint>& a, bool inverse = false) {
    int n = a.size();
    if(n == 1) {
        return a;
    } else {
        vector<modint> e(n / 2), o(n / 2);
        for(int j = 0; j < n; j++) {
            (j % 2 ? o : e)[j / 2] = a[j];
        }
        vector<modint> ntt_e = ntt(e, inverse), ntt_o = ntt(o, inverse), ans(n);
        for(int j = 0; j < n; j++) {
            ans[j] = ntt_e[j % (n / 2)] + ((inverse ? ~W : W) ^ (K / n * j)) * ntt_o[j % (n / 2)] / (inverse ? 2 : 1);
        }
        return ans;
    }
}
vector<modint> operator*(const vector<modint>& A, const vector<modint>& B) {
    vector<modint> a = ntt(pad(A, A.size())), b = ntt(pad(B, B.size())), c(a.size());
    for(int j = 0; j < a.size(); j++) {
        c[j] = a[j] * b[j];
    }
    return ntt(c, true);
}
vector<modint> polynomial_multiply(const vector<modint>& A, const vector<modint>& B) {
    int product_size = A.size() + B.size() - 1;
    return pad(A, product_size) * pad(B, product_size);
}
vector<modint> operator^(const vector<modint>& X, long long y) {
    using f = function<vector<modint>(const vector<modint>&, long long)>;
    f poly_pow = [&](const vector<modint>& x, long long y) {
        if(y == 0) {
            vector<modint> id(x.size()); id[0] = 1;
            return id;
        } else {
            auto z = poly_pow(x, (y / 2));
            return y % 2 ? z * z * x : z * z;
        }
    };
    auto x = X;
    x.resize((X.size() - 1) * y + 1);
    return poly_pow(x, y);
}
