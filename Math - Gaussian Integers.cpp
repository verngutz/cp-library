#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
struct gaussian_int {
    T a, b;
    gaussian_int(T a, T b) : a(a), b(b) {}
    T real() { return a; }
    T imag() { return b; }
    bool operator==(const gaussian_int<T>& y) const { return a == y.a and b == y.b; }
    bool operator!=(const gaussian_int<T>& y) const { return not (*this == y); }
    gaussian_int<T> operator+(const gaussian_int<T>& y) const {
        return gaussian_int<T>(a + y.a, b + y.b);
    }
    gaussian_int<T> operator*(const gaussian_int<T>& y) const {
        return gaussian_int<T>(a * y.a - b * y.a, a * y.b + b * y.a);
    }
    gaussian_int<T> operator^(const ll y) const {
        if(y == 0) {
            return gaussian_int(1, 0);
        } else {
            gaussian_int<T> z = *this^(y / 2);
            return z * z * (y % 2 ? *this : gaussian_int(1, 0));
        }
    }
    gaussian_int<T> operator-() const {
        return gaussian_int<T>(-a, -b);
    }
    gaussian_int<T> operator-(const gaussian_int<T>& y) const { return *this + -y; }
    gaussian_int<T>& operator=(const gaussian_int<T>& y) { a = y.a, b = y.b; return *this; }
    gaussian_int<T>& operator+=(const gaussian_int<T>& y) { return *this = *this + y; }
    gaussian_int<T>& operator*=(const gaussian_int<T>& y) { return *this = *this * y; }
    gaussian_int<T>& operator^=(const gaussian_int<T>& y) { return *this = *this ^ y; }
    gaussian_int<T>& operator-=(const gaussian_int<T>& y) { return *this = *this - y; }
    gaussian_int<T> conj() const {
        return gaussian_int<T>(a, -b);
    }
    T norm() const {
        return a * a + b * b;
    }
};
template <typename T> ostream& operator<<(ostream& os, const gaussian_int<T>& x) { return os << "(" << x.a << ", " << x.b << ")"; }
template <typename T> istream& operator>>(istream& is, gaussian_int<T>& x) { return is >> x.a >> x.b; }
