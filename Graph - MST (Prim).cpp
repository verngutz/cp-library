#include <bits/stdc++.h>
#include "Graph - Adjacency List (weighted).cpp"
using namespace std;
using ll = long long;
template <bool Directed> ll mst(graph<Directed>& g, int s) {
    vector<bool> vis(g.n + 1, false);
    vector<ll> d(g.n + 1, numeric_limits<ll>::max());
    vector<edge> p(g.n + 1);
    d[s] = 0;
    priority_queue<pair<ll, int>> pq({{-d[s], s}});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(edge& e : g.adj[u]) {
                auto [u, v, w] = e;
                if(not vis[v] and d[v] > w) {
                    p[v] = e, d[v] = w;
                    pq.push({-d[v], v});
                }
            }
        }
    }
    return accumulate(d.begin(), d.end(), 0);
}
