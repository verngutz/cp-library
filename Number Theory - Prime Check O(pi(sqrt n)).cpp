#include <bits/stdc++.h>
#include "Number Theory - Prime Generate.cpp"
using namespace std;
// const int SQRTN = 10'000;
vector<int> primes = generate_primes(SQRTN);
bool is_prime(long long n) {
    bool ans = n != 1;
    for(int i = 0; ans and i < primes.size() and (long long)primes[i] * primes[i] <= n; i++) {
        ans &= n % primes[i] != 0;
    }
    return ans;
}
