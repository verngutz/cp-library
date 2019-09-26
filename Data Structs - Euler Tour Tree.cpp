#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename TEdge, bool Index> struct flat_tree {
    vector<int> tour, depth, d, f, component;
    flat_tree(graph<0, TEdge, Index>& g, int root = Index) : tour(g.size() + (g.edges.size() >> 1)), depth(g.adj.size()), d(g.adj.size()), f(g.adj.size()) {
        int timer = 0;
        component = dfs(g, [&](dfs_params<TEdge>& params) {
            params.pre_node = [&](int u) { tour[d[u] = f[u] = timer++] = u; };
            params.pre_edge = [&](TEdge& e) { depth[e.v] = depth[e.u] + 1; };
            params.pos_edge = [&](TEdge& e) { tour[f[e.u] = timer++] = e.u; };
            params.root = index;
        });
    }
};
