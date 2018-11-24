#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long n) {
    bool ans = n != 1;
    for(long long i = 2; ans and i * i <= n; i++) {
        ans &= n % i != 0;
    }
    return ans;
}
