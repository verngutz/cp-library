#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include "Number Theory - Primitive Root.cpp"
auto init = []() {
    set_M(998244353);
    return 0;
} ();
const modint R = primitive_root(M);
const ll K = (M - 1) & -(M - 1);
const modint W = R ^ ((M - 1) / K);
modint w(int len, bool inverse) {
    return ((inverse ? ~W : W) ^ (K / len));
}
