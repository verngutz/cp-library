#include <bits/stdc++.h>
#include "Convolutions (Bitwise) - Covering Product.cpp"
#include "Math - Fast Pow.cpp"
using namespace std;
template <typename T> vector<T>& operator^=(vector<T>& x, long long y) {
    zeta(x);
    transform(x.begin(), x.end(), x.begin(), [y](T& xi) { return fpow(xi, y); });
    return mu(x);
}
template <typename T> vector<T> operator^(vector<T> x, long long y) { return x ^= y; }
