#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TEachPrime, typename TEachUniquePrime = function<void(T)>>
constexpr void factorize(T n, TEachPrime&& each_prime, TEachUniquePrime&& each_unique_prime = [](T) {}) {
    static_assert(is_convertible<decltype(each_prime), function<void(T)>>::value);
    static_assert(is_convertible<decltype(each_unique_prime), function<void(T)>>::value);
    for(T i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            each_unique_prime(i);
            while(n % i == 0) {
                each_prime(i);
                n /= i;
            }
        }
    }
    if(n > 1) {
        each_prime(n);
        each_unique_prime(n);
    }
}
