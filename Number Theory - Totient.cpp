#include "Number Theory - Factorization O(sqrt n).cpp"
using ll = long long;
ll phi(ll n) {
    if(n == 1) {
        return 0;
    } else {
        ll ans = n;
        factorize<ll>(n, [](ll) {}, [&](ll p) { ans -= ans / p; });
        return ans;
    }
}
