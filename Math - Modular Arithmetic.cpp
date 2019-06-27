#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
using namespace std;
#ifdef __TOTIENT_INCLUDED_
template <int M, int PHI_M = phi(M)> struct modint {
#else
template <int M, int PHI_M> struct modint {
#endif
    static const int MOD = M;
    int val;
    constexpr modint() : val(0) {}
    constexpr modint(int val) : val(val % M) { val += val < 0 ? M : 0; }
    constexpr modint(long long val) : modint(int(val % M)) {}
    constexpr modint(const modint& m) : val(m.val) {}
    constexpr explicit operator int() const { return val; }
    constexpr bool operator==(const modint& y) const { return val == y.val; }
    constexpr bool operator!=(const modint& y) const { return val != y.val; }
    constexpr bool operator< (const modint& y) const { return val <  y.val; }
    constexpr bool operator<=(const modint& y) const { return val <= y.val; }
    constexpr bool operator> (const modint& y) const { return val >  y.val; }
    constexpr bool operator>=(const modint& y) const { return val >= y.val; }
    constexpr modint& operator=(const modint& y) { val = y.val; return *this; }
    constexpr modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    constexpr modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    constexpr modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    constexpr modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    constexpr modint& operator^=(ll y) { fpow_eq(*this, y); return *this; }
    constexpr modint operator+(const modint& y) const { return modint(val) += y; }
    constexpr modint operator-(const modint& y) const { return modint(val) -= y; }
    constexpr modint operator*(const modint& y) const { return modint(val) *= y; }
    constexpr modint operator/(const modint& y) const { return modint(val) /= y; }
    constexpr modint operator^(ll y) const { return modint(val) ^= y; }
    constexpr modint operator-() const { return modint(0) -= *this; }
    constexpr modint operator~() const { return modint(1) /= *this; }
    constexpr modint& operator++() { val = val == M - 1 ? 0 : val + 1; return *this; }
    constexpr modint& operator--() { val = val == 0 ? M - 1 : val - 1; return *this; }
    constexpr modint operator++(int) { modint m = *this; ++(*this); return m; }
    constexpr modint operator--(int) { modint m = *this; --(*this); return m; }
    friend constexpr modint operator+(long long x, const modint& y) { return modint(x) + y; }
    friend constexpr modint operator*(long long x, const modint& y) { return modint(x) * y; }
    friend constexpr modint operator-(long long x, const modint& y) { return modint(x) - y; }
    friend constexpr modint operator/(long long x, const modint& y) { return modint(x) / y; }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
    friend istream& operator>>(istream& is, modint& m) { ll val; is >> val; m = modint(val); return is; }
};
const int M = 1'000'000'007;
using mint = modint<M, M - 1>;
