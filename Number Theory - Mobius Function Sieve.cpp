#include <bits/stdc++.h>
using namespace std;
vector<int> generate_mu(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> mu(n + 1, 1);
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i; j <= n; j += i) {
                is_prime[j] = false;
                mu[j] *= j / i % i == 0 ? 0 : -1;
            }
        }
    }
    return mu;
}
