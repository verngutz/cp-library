#ifndef __MODINT_INCLUDED_
#define __MODINT_INCLUDED_
// WARNING: use with caution; significant constant factor slowdown
#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
#include "Number Theory - Totient.cpp"
using namespace std;
int M, PHI_M;
void set_M(int m) {
    M = m, PHI_M = phi(m);
}
struct modint {
    int val;
    modint() : val(0) {}
    modint(int val) : val(val % M) { val += val < 0 ? M : 0; }
    modint(long long val) : modint(int(val % M)) {}
    modint(const modint& m) : val(m.val) {}
    explicit operator int() const { return val; }
    bool operator==(const modint& y) const { return val == y.val; }
    bool operator!=(const modint& y) const { return val != y.val; }
    bool operator< (const modint& y) const { return val <  y.val; }
    bool operator<=(const modint& y) const { return val <= y.val; }
    bool operator> (const modint& y) const { return val >  y.val; }
    bool operator>=(const modint& y) const { return val >= y.val; }
    modint& operator=(const modint& y) { val = y.val; return *this; }
    modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    modint& operator^=(ll y) { fpow_eq(*this, y); return *this; }
    modint operator+(const modint& y) const { return modint(val) += y; }
    modint operator-(const modint& y) const { return modint(val) -= y; }
    modint operator*(const modint& y) const { return modint(val) *= y; }
    modint operator/(const modint& y) const { return modint(val) /= y; }
    modint operator^(ll y) const { return modint(val) ^= y; }
    modint operator-() const { return modint(0) -= *this; }
    modint operator~() const { return modint(1) /= *this; }
    modint& operator++() { val = val == M - 1 ? 0 : val + 1; return *this; }
    modint& operator--() { val = val == 0 ? M - 1 : val - 1; return *this; }
    modint operator++(int) { modint m = *this; ++(*this); return m; }
    modint operator--(int) { modint m = *this; --(*this); return m; }
};
ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
istream& operator>>(istream& is, modint& m) { is >> m.val; m.val %= M; return is; }
bool operator==(long long x, const modint& y) { return modint((x + M) % M) == y; }
bool operator!=(long long x, const modint& y) { return modint((x + M) % M) != y; }
bool operator< (long long x, const modint& y) { return modint((x + M) % M) <  y; }
bool operator<=(long long x, const modint& y) { return modint((x + M) % M) <= y; }
bool operator> (long long x, const modint& y) { return modint((x + M) % M) >  y; }
bool operator>=(long long x, const modint& y) { return modint((x + M) % M) >= y; }
modint operator+(long long x, const modint& y) { return modint((x + M) % M) + y; }
modint operator*(long long x, const modint& y) { return modint((x + M) % M) * y; }
modint operator-(long long x, const modint& y) { return modint((x + M) % M) - y; }
modint operator/(long long x, const modint& y) { return modint((x + M) % M) / y; }
#endif
