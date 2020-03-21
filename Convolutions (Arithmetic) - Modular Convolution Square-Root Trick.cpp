#include <bits/stdc++.h>
#include "FFTs - Convolution (Discrete Fourier Transform).cpp"
using namespace std;
template <typename T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
    transform(a.begin(), a.end(), b.begin(), a.begin(), plus<T>());
    return a;
}
template <typename T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
    transform(a.begin(), a.end(), b.begin(), a.begin(), minus<T>());
    return a;
}
template <typename T> vector<T> operator+(vector<T> a, const vector<T>& b) { return a += b; }
template <typename T> vector<T> operator-(vector<T> a, const vector<T>& b) { return a -= b; }
template <int C = int(sqrt(mint::MOD) + 0.5)> vector<mint>& operator*=(vector<mint>& a, vector<mint>& b) {
    vector<complex<double>> a0(a.size()), a1(a.size()), b0(b.size()), b1(b.size());
    transform(a.begin(), a.end(), a0.begin(), [](mint& ai) { return ai.val % C; });
    transform(a.begin(), a.end(), a1.begin(), [](mint& ai) { return ai.val / C; });
    transform(b.begin(), b.end(), b0.begin(), [](mint& bi) { return bi.val % C; });
    transform(b.begin(), b.end(), b1.begin(), [](mint& bi) { return bi.val / C; });
    vector<complex<double>> z0 = a0 * b0, &z1 = (a0 += a1) *= (b0 += b1), &z2 = a1 *= b1;
    (z1 -= z0) -= z2;
    for(int i = 0; i < a.size(); i++) {
        a[i] = mint(z0[i]) + mint(z1[i]) * C + mint(z2[i]) * C * C;
    }
    return a;
}
template <int C = int(sqrt(mint::MOD) + 0.5)> vector<mint> operator*(vector<mint> a, vector<mint>& b) { return a *= b; }
