#include <bits/stdc++.h>
#include "Number Theory - Miller-Rabin Primality Test.cpp"
using namespace std;
random_device rd;
ll f(ll x, ll c, ll n) {
    return (mul(x, x, n) + c) % n;
}
ll rho(ll n) {
    if(n % 2 == 0) {
        return 2;
    } else {
        uniform_int_distribution<ll> dist(0, n - 1);
        ll divisor;
        ll c = dist(rd);
        ll x = dist(rd);
        ll y = x;
        do {
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);
            divisor = gcd(abs(y - x), n);
        } while(divisor == 1);
        return divisor;
    }
}
void factorize(ll n, vector<ll>& ans) {
    if(n == 0 or n == 1) {
        return;
    } else if(is_prime(n)) {
        ans.push_back(n);
    } else {
        ll divisor = rho(n);
        factorize(divisor, ans);
        factorize(n / divisor, ans);
    }
}
