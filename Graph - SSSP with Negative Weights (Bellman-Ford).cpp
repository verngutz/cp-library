#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge { int u, v, w; };
vector<ll> sssp(int n, vector<edge>& edges, int s) {
    int inf = accumulate(edges.begin(), edges.end(), 0, [](ll sum, edge& e) { return sum + e.w; });
    vector<ll> d(n + 1, inf);
    vector<edge> p(n + 1);
    vector<bool> neg_cycle(n + 1);
    d[s] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(edge& e : edges) {
            if(d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                p[e.v] = e;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(edge& e : edges) {
            if(d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                neg_cycle[e.v] = true;
            }
        }
    }
    return d;
}
