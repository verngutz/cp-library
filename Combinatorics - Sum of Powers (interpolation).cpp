#include "Math - Modular Arithmetic.cpp"
#include "Math - Polynomials (Extrapolation).cpp"
template <typename T = mint> T sum_of_powers(ll n, int p) {
    vector<T> y(p + 2);
    T s = 0;
    for(int x = 0; x <= min(n, ll(p + 1)); x++) {
        y[x] = (s += mint(x) ^ p);
    }
    return n <= p + 1 ? y[n] : extrapolate(y, n);
}
