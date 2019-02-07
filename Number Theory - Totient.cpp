#include "Number Theory - Factorization O(sqrt n).cpp"
using ll = long long;
ll phi(ll n) {
    ll ans = n;
    factorize<ll>(n, [](ll) {}, [&](ll p) { ans -= ans / p; });
    return ans;
}
