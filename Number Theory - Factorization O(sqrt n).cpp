#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>&;
template <typename T> void factorize(T n, f<void(T)> each_divisor, f<void(T)> each_prime = [](T) {}) {
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
