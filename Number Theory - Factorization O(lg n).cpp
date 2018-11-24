#include <bits/stdc++.h>
using namespace std;
vector<int> generate_largest_divisors(int n) {
    vector<bool> is_prime(n+1);
    vector<int> largest_prime_divisor(n+1);
    vector<int> primes;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            largest_prime_divisor[i] = i;
            primes.push_back(i);
            for(int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
                largest_prime_divisor[j] = i;
            }
        }
    }
    return largest_prime_divisor;
}
const int N;
vector<int> largest_prime_divisor = generate_largest_divisors(N);
map<int, int> factorize(int n) {
    map<int, int> factors;
    while(n > 1) {
        factors[largest_prime_divisor[n]]++;
        n /= largest_prime_divisor[n];
    }
    return factors;
}