using ll = long long;
template <typename T = ll> T C(ll n, ll k) {
    if(k < 0 or (n >= 0 and k > n)) return 0;
    if(n >= 0) k = min(k, n - k);
    T ans = 1;
    for(ll i = 0; i < k; i++) {
        ans *= n - i;
        ans /= i + 1;
    }
    return ans;
}