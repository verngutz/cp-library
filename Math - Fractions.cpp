#include <bits/stdc++.h>
using namespace std;
struct fraction {
    long long n, d;
    fraction(long long n=0, long long d=1) : n(n), d(d) { reduce(); }
    void reduce() {
        long long sgn = ((n >= 0 and d >= 0) or (n < 0 and d < 0)) ? 1 : -1;
        long long g = __gcd(abs(n), abs(d));
        n = sgn * abs(n) / g;
        d = abs(d) / g;
    }
    bool operator==(const fraction& f) const { return n == f.n and d == f.d; }
    bool operator!=(const fraction& f) const { return not (*this == f); }
    bool operator<(const fraction& f) const { return n * f.d < d * f.n; }
    bool operator<=(const fraction& f) const { return operator<(f) or operator==(f); }
    bool operator>(const fraction& f) const { return not operator<=(f); }
    bool operator>=(const fraction& f) const { return operator>(f) or operator==(f); }
    fraction operator-() const { return fraction(-n, d); }
    fraction operator~() const { return fraction(d, n); }
    fraction operator+(const fraction& f) const { return fraction(n * f.d + d * f.n, d * f.d); }
    fraction operator*(const fraction& f) const { return fraction(n * f.n, d * f.d); }
    fraction operator-(const fraction& f) const { return *this + -f; }
    fraction operator/(const fraction& f) const { return *this * ~f; }
    fraction& operator=(const fraction& f) { n = f.n, d = f.d; return *this; }
    fraction& operator+=(const fraction& f) { return *this = *this + f; }
    fraction& operator-=(const fraction& f) { return *this = *this - f; }
    fraction& operator*=(const fraction& f) { return *this = *this * f; }
    fraction& operator/=(const fraction& f) { return *this = *this / f; }
};
ostream& operator<<(ostream& os, const fraction& f) { return os << f.n << "/" << f.d; }
bool operator==(long long x, const fraction& y) { return fraction(x) == y; }
bool operator!=(long long x, const fraction& y) { return fraction(x) != y; }
bool operator< (long long x, const fraction& y) { return fraction(x) <  y; }
bool operator<=(long long x, const fraction& y) { return fraction(x) <= y; }
bool operator> (long long x, const fraction& y) { return fraction(x) >  y; }
bool operator>=(long long x, const fraction& y) { return fraction(x) >= y; }
fraction operator+(long long x, const fraction& y) { return fraction(x) + y; }
fraction operator*(long long x, const fraction& y) { return fraction(x) * y; }
fraction operator-(long long x, const fraction& y) { return fraction(x) - y; }
fraction operator/(long long x, const fraction& y) { return fraction(x) / y; }
