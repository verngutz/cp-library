#include <bits/stdc++.h>
using namespace std;
struct edge { int u, v, w; };
template <bool Directed>
struct graph {
    int n;
    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n + 1) {}
    void add_edge(int u, int v, int w) {
        adj[u].push_back({u, v, w});
        if(not Directed) adj[v].push_back({v, u, w});
    }
};
