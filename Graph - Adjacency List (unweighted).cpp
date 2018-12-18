#include <bits/stdc++.h>
using namespace std;
struct edge { int u, v, i; };
template <bool Directed> struct graph {
    int n;
    vector<edge> edges;
    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n + 1) {}
    void add_edge(int u, int v) {
        int i = edges.size();
        edges.push_back({u, v, i});
        adj[u].push_back({u, v, i});
        if(not Directed) adj[v].push_back({v, u, i});
    }
};
