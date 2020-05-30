#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> divisors(ll n) {
    vector<ll> ans;
    for(ll d = 1; d * d <= n; d++) {
        if(n % d == 0) {
            ans.push_back(d);
            if(d * d != n) {
                ans.push_back(n / d);
            }
        }
    }
    return ans;
}