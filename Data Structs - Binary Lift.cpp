#include <bits/stdc++.h>
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename TEdge, bool Index> struct binary_lift {
    vector<int> depth;
    vector<vector<int>> p;
    binary_lift(graph<0, TEdge, Index>& g, const vector<int>& roots = {Index}) : depth(g.adj.size()), p(g.adj.size()) {
        for(int root : roots) {
            dfs(g, [&](dfs_params<TEdge>& params) {
                params.root = root;
                params.pre_edge = [&](TEdge& e) {
                    p[e.v].resize(__lg(depth[e.v] = depth[e.u] + 1) + 1);
                    p[e.v][0] = e.u;
                    build_ancestors(e.v);
                };
                params.reuse_previous_components = true;
            });
        }
    }
    binary_lift(vector<int>& p0, vector<int>& topological_order) : depth(p0.size()), p(p0.size()) {
        for(int u : topological_order) {
            p[u].resize(__lg(depth[u] = depth[p0[u]] + 1) + 1);
            p[u][0] = p0[u];
            build_ancestors(u);
        }
    }
    void build_ancestors(int u) {
        for(int pow2 = 1; pow2 <= __lg(depth[u]); pow2++) {
            p[u][pow2] = p[p[u][pow2 - 1]][pow2 - 1];
        }
    }
    int kth_ancestor(int u, int k) {
        return k == 0 ? u : kth_ancestor(p[u][__lg(k & -k)], k - (k & -k));
    }
    template <typename Can> int bsearch_kth_ancestor(int u, const Can& can) {
        for(int pow2 = (depth[u] ? __lg(depth[u]) : -1); pow2 >= 0; pow2--) {
            if((1 << pow2) <= depth[u] and can(p[u][pow2])) {
                u = p[u][pow2];
            }
        }
        return u;
    }
    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        v = kth_ancestor(v, depth[v] - depth[u]);
        for(int pow2 = (depth[u] ? __lg(depth[u]) : -1); pow2 >= 0; pow2--) {
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
