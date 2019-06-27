#include <bits/stdc++.h>
using namespace std;
template <typename T = long long> T F(int n) {
    static vector<T> f = {0, 1};
    while(f.size() <= n) {
        f.push_back(f[f.size() - 1] + f[f.size() - 2]);
    }
    return f[n];
}
