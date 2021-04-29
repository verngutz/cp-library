#include <bits/stdc++.h>
using namespace std;
struct factorizer {
    vector<int> is_prime, largest_prime_divisor;
    factorizer(int n) : is_prime(n + 1, true), largest_prime_divisor(n + 1) {
        for(int i = 2; i <= n; i++) {
            if(is_prime[i]) {
                largest_prime_divisor[i] = i;
                for(int j = 2 * i; j <= n; j += i) {
                    is_prime[j] = false, largest_prime_divisor[j] = i;
                }
            }
        }
    }
    template <typename T, typename TEachPrime, typename TEachUniquePrime = function<void(T)>>
    void factorize(T n, TEachPrime&& each_prime, TEachUniquePrime&& each_unique_prime = [](T) {}) {
        static_assert(is_convertible<decltype(each_prime), function<void(T)>>::value);
        static_assert(is_convertible<decltype(each_unique_prime), function<void(T)>>::value);
        while(n > 1) {
            int d = largest_prime_divisor[n];
            each_prime(d);
            if(d != largest_prime_divisor[n /= d]) {
                each_unique_prime(d);
            }
        }
    }
};
