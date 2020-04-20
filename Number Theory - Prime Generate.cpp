#include <bits/stdc++.h>
using namespace std;
vector<int> generate_primes(int n) {
    vector<bool> is_prime(n+1);
    vector<int> primes;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
