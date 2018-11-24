#include <bits/stdc++.h>
using namespace std;
template<typename T>
map<T, int> factorize(T n) {
    map<T, int> factors;
    for(T i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if(n > 1) {
        factors[n]++;
    }
    return factors;
}
