#include <bits/stdc++.h>
#include "Number Theory - Factorization O(sqrt n).cpp"
using namespace std;
using ll = long long;
ll sigma(ll n) {
    map<ll, int> occ;
    factorize(n, [&](ll d) { occ[d]++; }, [](ll) {});
    return accumulate(occ.begin(), occ.end(), 1ll, [](ll prod, const pair<ll, int>& p) {
        return prod * p.second;
    });
}
