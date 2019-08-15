#include <bits/stdc++.h>
#include "Number Theory - Factorization O(sqrt n).cpp"
using namespace std;
using ll = long long;
ll sigma(ll n) {
    ll prod = 1, occ = 0, prev_d = 0;
    factorize(n, [&](ll d) {
        if(prev_d != d) {
            prod *= occ + 1;
            occ = 0;
        }
        occ++;
        prev_d = d;
    });
    return prod * (occ + 1);
}
