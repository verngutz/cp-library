#include <bits/stdc++.h>
using namespace std;
struct gf2int {
    int val;
    constexpr gf2int(int x = 0) : val(x) {}
    constexpr operator int() const { return val; }
    constexpr bool operator==(const gf2int& other) const { return val == other.val; }
    constexpr bool operator!=(const gf2int& other) const { return val != other.val; }
    constexpr gf2int& operator+=(const gf2int& other) { val ^= other.val; return *this; }; 
    constexpr gf2int& operator-=(const gf2int& other) { val ^= other.val; return *this; };
    constexpr gf2int& operator*=(const gf2int& other) { val *= other.val; return *this; };
    constexpr gf2int& operator/=(const gf2int& other) { val /= other.val; return *this; };
    constexpr gf2int operator+(const gf2int& other) const { return move(gf2int(val) += other); }
    constexpr gf2int operator-(const gf2int& other) const { return move(gf2int(val) -= other); }
    constexpr gf2int operator*(const gf2int& other) const { return move(gf2int(val) *= other); }
    constexpr gf2int operator/(const gf2int& other) const { return move(gf2int(val) /= other); }
    friend ostream& operator<<(ostream& os, const gf2int& g) { return os << g.val; }
    friend istream& operator>>(istream& is, gf2int& g) { return is >> g.val; }
};
