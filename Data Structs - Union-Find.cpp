#include <bits/stdc++.h>
using namespace std;
struct ufds {
    vector<int> p;
    ufds(int n) : p(n + 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }
    void onion(int u, int v) {
        if(find(u) != find(v)) {
            p[find(u)] = find(v);
        }
    }
};
