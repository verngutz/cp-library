#include <bits/stdc++.h>
using namespace std;
vector<int> generate_sigma0(int n) {
    vector<int> sigma0(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            sigma0[j]++;
        }
    }
    return sigma0;
}