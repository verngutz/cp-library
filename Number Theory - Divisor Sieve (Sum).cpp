#include <bits/stdc++.h>
using namespace std;
vector<int> generate_sigma1(int n) {
    vector<int> sigma1(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            sigma1[j] += i;
        }
    }
    return sigma1;
}