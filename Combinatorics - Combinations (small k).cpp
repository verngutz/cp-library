#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll C(ll n, ll k) {
    if(k < 0) return 0;
    if(k == 0 or k == n) return 1;
    if(n >= 0) k = min(k, n - k);
    ll ans = 1, j = 2;
    for(ll i = 0; i < k; i++) {
        ans *= n - i;
        while(j <= k and ans % j == 0) {
            ans /= j;
            j++;
        }
    }
    return j == (k + 1) ? ans : 0;
}
#endif
