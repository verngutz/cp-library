#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F(int n) {
    static vector<ll> f = {0, 1};
    while(f.size() <= n) {
        int x = f.size();
        f.push_back(f[x - 1] + f[x - 2]);
    }
    return f[n];
}
