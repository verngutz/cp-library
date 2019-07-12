#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TEachDivisor, typename TEachPrime>
constexpr void factorize(T n, TEachDivisor each_divisor, TEachPrime each_prime = [](T) {}) {
    static_assert(is_convertible<decltype(each_divisor), function<void(T)>>::value,
        "each_divisor must be void(T)");
    static_assert(is_convertible<decltype(each_prime), function<void(T)>>::value,
        "each_prime must be void(T)");
    for(T i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            each_prime(i);
            while(n % i == 0) {
                each_divisor(i);
                n /= i;
            }
        }
    }
    if(n > 1) {
        each_divisor(n);
        each_prime(n);
    }
}
