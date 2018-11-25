#include <bits/stdc++.h>
using namespace std;
struct adj_edge { int i, u, v; };
template <bool Directed> struct graph {
    int n;
    vector<adj_edge> edges;
    vector<vector<adj_edge>> adj;
    graph(int n) : n(n), adj(n + 1) {}
    void add_edge(int u, int v) {
        int i = edges.size();
        edges.push_back({i, u, v});
        adj[u].push_back({i, u, v});
        if(not Directed) adj[v].push_back({i, v, u});
    }
};
