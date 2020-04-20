#include <bits/stdc++.h>
#include "Misc - Lg.cpp"
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename TEdge> struct binary_lift {
    vector<int> depth;
    vector<vector<int>> p;
    binary_lift(graph<0, TEdge>& g) : depth(g.n + 1), p(g.n + 1) {
        dfs(g, 1, [&](int u, TEdge* from) {
            if(from) {
                p[u].push_back(from->u);
                depth[u] = depth[from->u] + 1;
                build_ancestors(u);
            }
        });
    }
    binary_lift(vector<int>& p0, vector<int>& topological_order) : depth(p0.size()), p(p0.size()) {
        for(int u : topological_order) {
            p[u].push_back(p0[u]);
            depth[u] = depth[p0[u]] + 1;
            build_ancestors(u);
        }
    }
    void build_ancestors(int u) {
        for(int pow2 = 1; pow2 <= lg(depth[u]); pow2++) {
            p[u].push_back(p[p[u][pow2 - 1]][pow2 - 1]);
        }
    }
    int kth_ancestor(int u, int k) {
        return k == 0 ? u : kth_ancestor(p[u][lg(k & -k)], k - (k & -k));
    }
    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        v = kth_ancestor(v, depth[v] - depth[u]);
        for(int pow2 = lg(depth[u]); pow2 >= 0; pow2--) {
            if((1 << pow2) <= depth[u] and p[u][pow2] != p[v][pow2]) {
                u = p[u][pow2], v = p[v][pow2];
            }
        }
        return u == v ? u : p[u][0];
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
