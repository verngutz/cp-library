#ifndef __MODINT_INCLUDED_
#define __MODINT_INCLUDED_
// WARNING: use with caution; significant constant factor slowdown
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// const ll M = 1'000'000'007;
struct modint {
    ll val;
    modint() : val(0) {}
    modint(ll val) : val(val) {}
    explicit operator ll() const { return val; }
    bool operator==(const modint& y) const { return val == y.val; }
    bool operator!=(const modint& y) const { return val != y.val; }
    bool operator< (const modint& y) const { return val <  y.val; }
    bool operator<=(const modint& y) const { return val <= y.val; }
    bool operator> (const modint& y) const { return val >  y.val; }
    bool operator>=(const modint& y) const { return val >= y.val; }
    modint operator+(const modint& y) const { return (val + y.val) % M; }
    modint operator*(const modint& y) const { return val * y.val % M; }
    modint operator^(const ll y) const {
        if(y == 0) {
            return 1;
        } else {
            modint z = *this^(y / 2);
            return z * z * (y % 2 ? *this : 1);
        }
    }
    modint operator^(const modint& y) const { return *this ^ y.val; }
    modint operator-() const { return M - val; }
    modint operator~() const { return *this ^ (M - 2); }
    modint operator-(const modint& y) const { return *this + -y; }
    modint operator/(const modint& y) const { return *this * ~y; }
    modint& operator=(const modint& y) { val = y.val; return *this; }
    modint& operator+=(const modint& y) { return *this = *this + y; }
    modint& operator*=(const modint& y) { return *this = *this * y; }
    modint& operator^=(const modint& y) { return *this = *this ^ y; }
    modint& operator-=(const modint& y) { return *this = *this - y; }
    modint& operator/=(const modint& y) { return *this = *this / y; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint m = *this; ++(*this); return m; }
    modint operator--(int) { modint m = *this; --(*this); return m; }
};
ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
istream& operator>>(istream& is, modint& m) { is >> m.val; m.val %= M; return is; }
bool operator==(long long x, const modint& y) { return modint(x + M % M) == y; }
bool operator!=(long long x, const modint& y) { return modint(x + M % M) != y; }
bool operator< (long long x, const modint& y) { return modint(x + M % M) <  y; }
bool operator<=(long long x, const modint& y) { return modint(x + M % M) <= y; }
bool operator> (long long x, const modint& y) { return modint(x + M % M) >  y; }
bool operator>=(long long x, const modint& y) { return modint(x + M % M) >= y; }
modint operator+(long long x, const modint& y) { return modint(x + M % M) + y; }
modint operator*(long long x, const modint& y) { return modint(x + M % M) * y; }
modint operator-(long long x, const modint& y) { return modint(x + M % M) - y; }
modint operator/(long long x, const modint& y) { return modint(x + M % M) / y; }
#endif
