#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include "Number Theory - Primitive Root.cpp"
template <typename T = mint> T w(int len, bool inverse) {
    static const int K = (T::MOD - 1) & -(T::MOD - 1);
    static const T W = primitive_root<T::MOD>() ^ ((T::MOD - 1) / K);
    return ((inverse ? ~W : W) ^ (K / len));
}
