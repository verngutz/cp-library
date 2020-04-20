#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool is_prime(ll n) {
    bool ans = n != 1;
    for(ll i = 2; ans and i * i <= n; i++) {
        ans &= n % i != 0;
    }
    return ans;
}
