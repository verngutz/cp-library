#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge { int u, v; ll c, f; };
struct graph {
    int n;
    vector<edge> edges;
    vector<vector<int>> adj;
    graph(int n) : n(n), adj(n + 1) {}
    void add_edge(int u, int v, ll c) {
        if(u != v) {
            adj[u].push_back(edges.size()); edges.push_back({u, v, c, 0});
            adj[v].push_back(edges.size()); edges.push_back({v, u, 0, 0});
        }
    }
};
ll max_flow(graph& g, int s, int t) {
    vector<int> d(g.n + 1), adj_ptr(g.n + 1);
    auto make_level_graph = [&]() {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q({s});
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(int i : g.adj[u]) {
                auto [u, v, c, f] = g.edges[i];
                if(c - f > 0 and d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    };
    function<ll(int, ll)> augment = [&](int u, ll b) {
        if(u == t) return b;
        for(int& j = adj_ptr[u]; j < g.adj[u].size(); j++) {
            edge& forward = g.edges[g.adj[u][j]];
            edge& reverse = g.edges[g.adj[u][j] ^ 1];
            auto& [uu, v, c, f] = forward;
            if(ll df; d[v] == d[u] + 1 and c - f > 0 and (df = augment(v, min(b, c - f)))) {
                f += df, reverse.f -= df;
                return df;
            }
        }
        return 0ll;
    };
    ll ans = 0;
    while(make_level_graph()) {
        fill(adj_ptr.begin(), adj_ptr.end(), 0);
        while(ll df = augment(s, numeric_limits<ll>::max())) {
            ans += df;
        }
    }
    return ans;
}
