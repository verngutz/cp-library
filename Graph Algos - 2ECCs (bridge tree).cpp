#include <bits/stdc++.h>
#include "Graph Algos - 2ECCs.cpp"
using namespace std;
template <typename TEdge, bool Index> pair<vector<int>, graph<0, TEdge, Index>> build_bridge_tree(graph<0, TEdge, Index>& g,
const vector<int>& cut_edge, const vector<vector<int>>& _2eccs) {
    vector<int> _2ecc_id(g.adj.size());
    for(int i = 0; i < _2eccs.size(); i++) {
        for(int u : _2eccs[i]) {
            _2ecc_id[u] = i + Index;
        }
    }
    graph<0, edge, Index> bridge_tree(_2eccs.size());
    for(int e = 0; e < g.edges.size(); e++) {
        if(cut_edge[e] and g(e).u < g(e).v) {
            bridge_tree.add_edge({_2ecc_id[g(e).u], _2ecc_id[g(e).v]});
        }
    }
    return {_2ecc_id, bridge_tree};
}
template <typename TEdge, bool Index> pair<vector<int>, graph<0, TEdge, Index>> build_bridge_tree(graph<0, TEdge, Index>& g) {
    auto [cut_edge, _2eccs] = find_2eccs(g);
    return build_bridge_tree(g, cut_edge, _2eccs);
}
