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
