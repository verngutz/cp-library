#include <bits/stdc++.h>
using namespace std;
template<typename T>
vector<T> prime_divisors(T n) {
    vector<T> divisors;
    for(T i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
        }
        while(n % i == 0) {
            n /= i;
        }
    }
    if(n > 1) {
        divisors.push_back(n);
    }
    return divisors;
}
