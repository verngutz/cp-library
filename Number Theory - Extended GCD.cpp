#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ex_gcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1, y = 0;
    } else {
        ll xx, yy;
        ex_gcd(b, a % b, xx, yy);
        x = yy, y = xx - a / b * yy;
    }
}
bool ex_gcd_pos(ll a, ll b, ll n, ll& x, ll& y) {
    ll g = gcd(a, b);
    if(n % g == 0) {
        a /= g, b /= g, n /= g;
        ll xx, yy;
        ex_gcd(a, b, xx, yy);
        if(xx < 0 and yy < 0) {
            return false;
        } else {
            if(xx < 0) {
                ll t = -xx / b + (-xx % b != 0);
                x = xx + t * b, y = yy - t * a;
            }
            if(yy < 0) {
                ll t = -yy / a + (-yy % a != 0);
                x = xx - t * b, y = yy + t * a;
            }
            return x >= 0 and y >= 0;
        }
    } else {
        return false;
    }
}
