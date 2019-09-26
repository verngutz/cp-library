#include <bits/stdc++.h>
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename TEdge, bool Index> struct flat_tree {
    vector<int> p, depth, head, d, f;
    flat_tree(graph<0, TEdge, Index>& g, int root = Index) 
    : p(g.adj.size()), depth(g.adj.size()), head(g.adj.size()), d(g.adj.size()), f(g.adj.size()) {
        vector<int> size(g.adj.size(), 1);
        dfs(g, [&](dfs_params<TEdge>& params) {
            params.pre_edge = [&](TEdge& e) {
                p[e.v] = e.u;
                depth[e.v] = depth[e.u] + 1;
            };
            params.pos_edge = [&](TEdge& e) {
                size[e.u] += size[e.v];
                swap(e, size[g(g[e.u][0]).v] < size[e.v] ? g(g[e.u][0]) : e);
            };
            params.root = root;
        });
        int timer = 1;
        dfs(g, [&](dfs_params<TEdge>& params) {
            params.pre_node = [&](int u) { d[u] = timer++; };
            params.pos_node = [&](int u) { f[u] = timer++; };
            params.pre_edge = [&](TEdge& e) { head[e.v] = e.v == g(g[e.u][0]).v ? head[e.u] : e.v; };
            params.root = root;
        });
    }
    int lca(int u, int v) {
        if(head[u] == head[v]) {
            return depth[u] < depth[v] ? u : v;
        } else {
            return depth[head[u]] < depth[head[v]] ? lca(u, p[head[v]]) : lca(p[head[u]], v);
        }
    }
};
