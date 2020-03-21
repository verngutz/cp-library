#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include "Number Theory - Primitive Root.cpp"
template <typename T = modint<998244353, 998244352>> T w(int len, bool inverse) {
    constexpr int M1 = T::MOD - 1;
    constexpr int K = M1 & -M1;
    constexpr T W = primitive_root<T::MOD>() ^ (M1 / K);
    return ((inverse ? ~W : W) ^ (K / len));
}
