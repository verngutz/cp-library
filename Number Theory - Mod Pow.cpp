using ll = long long;
// const ll M = 1'000'000'007;
ll mpow(ll x, ll y, ll m = M) {
    if(y == 0) {
        return 1;
    } else {
        ll z = mpow(x, y / 2, m);
        return z * z % m * (y % 2 ? x % m : 1) % m;
    }
}
