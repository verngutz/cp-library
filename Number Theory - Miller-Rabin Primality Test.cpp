#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mul(ll x, ll y, ll m) {
    if(y == 0) {
        return 0;
    } else {
        ll z = mul(x, y / 2, m);
        return ((z + z) % m + (y % 2 ? x % m : 0)) % m;
    }
}
ll mpow(ll x, ll r, ll y, ll m) {
    if(r == 0 and y == 0) {
        return 1;
    } else if (r > 0) {
        ll z = mpow(x, r - 1, y, m);
        return mul(z, z, m);
    } else {
        ll z = mpow(x, r, y / 2, m);
        return mul(mul(z, z, m), (y % 2 ? x % m : 1), m);
    }
}
array<int, 12> witnesses = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool is_prime(ll n) {
    if(n == 2) {
        return true;
    } else if(n < 2 or (n & 1) == 0) {
        return false;
    } else {
        int s = 0;
        ll d = n - 1;
        while((d & 1) == 0) {
            s++;
            d >>= 1;
        }
        for(int a : witnesses) {
            if(a >= n) {
                break;
            }
            bool composite = mpow(a, 0, d, n) != 1;
            for(int r = 0; r < s and composite; r++) {
                composite &= mpow(a, r, d, n) != n - 1;
            }
            if(composite) {
                return false;
            }
        }
        return true;
    }
}
