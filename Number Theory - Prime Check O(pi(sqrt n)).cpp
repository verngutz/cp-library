#include <bits/stdc++.h>
#include "Number Theory - Prime Generate.cpp"
using namespace std;
using ll = long long;
const int SQRTN;
vector<int> primes = generate_primes(SQRTN);
bool is_prime(ll n) {
    bool ans = n != 1;
    for(int i = 0; ans and i < primes.size() and ll(primes[i]) * primes[i] <= n; i++) {
        ans &= n % primes[i] != 0;
    }
    return ans;
}
