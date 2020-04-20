#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<T>& zeta(vector<T>& a) {
    int n = __lg(a.size());
    for(int i = 0; i < n; i++) {
        for(int mask = 0; mask < 1 << n; mask++) {
            if(mask & (1 << i)) {
                a[mask] += a[mask ^ (1 << i)];
            }
        }
    }
    return a;
}
