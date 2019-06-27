#include <bits/stdc++.h>
#include "Number Theory - Mod Pow.cpp"
#include "Number Theory - Totient.cpp"
using namespace std;
// find all/one x (mod M) such that a^x = b (mod c), or log_a b = x (mod c)
vector<ll> dlog(ll a, ll b, ll c, bool find_one = false) {
    a %= c, b %= c;
    ll offset = 0, g;
    while((g = __gcd(a, c)) > 1 and b % g == 0) {
        c /= g;
        b = int(b / g * mpow(a / g, phi(c) - 1, c));
        offset++;
    }
    vector<ll> ans;
    if(a > 0 and g == 1) {
        ll n = ll(sqrt(c) + 1), f1 = 1, f2 = 1;
        unordered_map<ll, vector<ll>> m;
        for(ll q = 0; q <= n; q++) {
            if(find_one) {
                m[b * f1 % c] = {q};
            } else {
                m[b * f1 % c].push_back(q);
            }
            if(q < n) f1 = f1 * a % c;
        }
        for(ll p = 1; p <= n; p++) {
            f2 = f2 * f1 % c;
            if(m.count(f2)) {
                for(ll q : m[f2]) {
                    ans.push_back(n * p - q + offset);
                }
                if(find_one) break;
            }
        }
    } else if(b == 1 or c == 1) {
        ans.push_back(offset);
    }
    return ans;
}
