#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge { int u, v, w; };
template <bool Directed>
struct graph {
    vector<vector<edge>> adj;
    int n;
    graph(int n) : n(n) {
        adj.resize(n + 1);
    }
    void add_edge(int u, int v, int w) {
        adj[u].push_back({u, v, w});
        if(not Directed) adj[v].push_back({v, u, w});
    }
};
template <bool Directed>
vector<ll> sssp(graph<Directed>& g, int s) {
    vector<bool> vis(g.n + 1, false);
    vector<ll> d(g.n + 1, -1);
    vector<int> p(g.n + 1, -1);
    d[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({-d[s], s});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(const auto& [u, v, w] : g.adj[u]) {
                if(not vis[v] and (d[v] > d[u] + w or d[v] == -1)) {
                    d[v] = d[u] + w, p[v] = u;
                    pq.push({-d[v], v});
                }
            }
        }
    }
    return d;
}
