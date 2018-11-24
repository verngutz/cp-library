using ll = long long;
ll phi(ll n) {
    if(n == 1) {
        return 0;
    } else {
        ll ans = n;
        for(ll i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                ans -= ans / i;
                while(n % i == 0) {
                    n /= i;
                }
            }
        }
        if(n > 1) {
            ans -= ans / n;
        }
        return ans;
    }
}
// const ll M = 1'000'000'007;
ll mpow(ll x, ll y, ll m=MOD) {
    if(y == 0) {
        return 1;
    } else {
        ll z = mpow(x, y / 2, m);
        return z * z % m * (y % 2 ? x % m : 1) % m;
    }
}
ll mpow(ll x, ll y, ll z, ll m) {
    if(y == 0) {
        return x % m;
    } else {
        ll ph = phi(m);
        ll yz = 1;
        for(ll i = 0; i < z and yz < ph; i++) {
            yz *= y;
        }
        return mpow(x, (yz < ph ? 0 : ph) + mpow(y, z, ph), m);
    }
}
