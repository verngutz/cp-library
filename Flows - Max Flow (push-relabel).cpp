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
    vector<int> height(g.n + 1), counter(2 * g.n);
    vector<ll> excess(g.n + 1);
    vector<bool> active(g.n + 1);
    queue<int> q;
    height[s] = g.n;
    auto push = [&](int u, int i, int df) {
        edge& forward = g.edges[i];
        edge& reverse = g.edges[i ^ 1];
        auto [uu, v, c, f] = forward;
        forward.f += df, reverse.f -= df;
        excess[v] += df, excess[u] -= df;
        if(excess[v] and not active[v] and v != s and v != t) {
            q.push(v), active[v] = true;
        }
    };
    for(int i : g.adj[s]) {
        push(s, i, g.edges[i].c);
    }
    auto discharge = [&](int u) {
        for(int j = 0; j < g.adj[u].size() and excess[u]; j++) {
            auto [uu, v, c, f] = g.edges[g.adj[u][j]];
            if(height[u] > height[v] and c - f > 0) {
                push(u, g.adj[u][j], min(excess[u], c - f));
            }
        }
    };
    auto relabel = [&](int u) {
        if(counter[height[u]] == 1) {
            for(int i = 1; i <= g.n; i++) {
                if(i != s and height[i] >= height[u]) {
                    counter[height[i]]--;
                    counter[height[i] = max(height[i], g.n + 1)]++;
                }
            }
        } else {
            counter[height[u]]--;
            height[u] = 2 * g.n - 1;
            for(int i : g.adj[u]) {
                auto [uu, v, c, f] = g.edges[i];
                if(c - f > 0) height[u] = min(height[u], height[v] + 1);
            }
            counter[height[u]]++;
        }
    };
    while(not q.empty()) {
        int u = q.front(); q.pop(), active[u] = false;
        discharge(u);
        if(excess[u] and not active[u]) {
            relabel(u);
            q.push(u), active[u] = true;
        }
    }
    return excess[t];
}
