#include <bits/stdc++.h>
#ifndef __FASTPOW_INCLUDED_
#include "Math - Fast Pow.cpp"
#endif
using namespace std;
#ifdef __TOTIENT_INCLUDED_
template <int M, int PHI_M = phi(M)> struct modint {
#else
template <int M, int PHI_M> struct modint {
#endif
    static constexpr int MOD = M;
    int val;
    constexpr modint() : val(0) {}
    constexpr modint(int x) : val(x % M) { val += val < 0 ? M : 0; }
    constexpr modint(long long x) : modint(int(x % M)) {}
    constexpr explicit operator int() const { return val; }
    constexpr bool operator==(const modint& y) const { return val == y.val; }
    constexpr bool operator!=(const modint& y) const { return val != y.val; }
    constexpr modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    constexpr modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    constexpr modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    constexpr modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    constexpr modint& operator^=(ll y) { return fpow_eq(*this, y); }
    constexpr modint operator+(const modint& y) const { return move(modint(*this) += y); }
    constexpr modint operator-(const modint& y) const { return move(modint(*this) -= y); }
    constexpr modint operator*(const modint& y) const { return move(modint(*this) *= y); }
    constexpr modint operator/(const modint& y) const { return move(modint(*this) /= y); }
    constexpr modint operator^(ll y) const { return move(modint(*this) ^= y); }
    constexpr modint operator-() const { return move(modint(0) -= *this); }
    constexpr modint operator~() const { return move(modint(1) /= *this); }
    constexpr modint& operator++() { val = val == M - 1 ? 0 : val + 1; return *this; }
    constexpr modint& operator--() { val = val == 0 ? M - 1 : val - 1; return *this; }
    constexpr modint operator++(int) { modint m = *this; ++(*this); return move(m); }
    constexpr modint operator--(int) { modint m = *this; --(*this); return move(m); }
    friend constexpr modint operator+(long long x, const modint& y) { return move(modint(x) += y); }
    friend constexpr modint operator*(long long x, const modint& y) { return move(modint(x) *= y); }
    friend constexpr modint operator-(long long x, const modint& y) { return move(modint(x) -= y); }
    friend constexpr modint operator/(long long x, const modint& y) { return move(modint(x) /= y); }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
    friend istream& operator>>(istream& is, modint& m) { ll val; is >> val; m = modint(val); return is; }
};
constexpr int M = 1'000'000'007;
using mint = modint<M, M - 1>;
mint operator""_m(unsigned long long int x) { return mint(ll(x)); }
