#include <bits/stdc++.h>
#include "Graph Algos - BCCs.cpp"
using namespace std;
template <bool Index> tuple<vector<int>, vector<int>, graph<0, edge, Index>> build_block_cut_tree(graph<0, edge, Index>& g,
const vector<int>& cut_node, const vector<vector<int>>& bccs) {
    int n_cut_nodes = count(cut_node.begin(), cut_node.end(), true);
    vector<int> bcc_edge_id(g.edges.size());
    vector<int> bcc_node_id(g.adj.size());
    for(int i = 0; i < bccs.size(); i++) {
        for(int e : bccs[i]) {
            bcc_edge_id[e] = bcc_edge_id[e ^ 1] = n_cut_nodes + i + Index;
        }
    }
    graph<0, edge, Index> block_cut_tree(n_cut_nodes + bccs.size());
    for(int u = Index; u < g.adj.size(); u++) if(cut_node[u]) {
        bcc_node_id[u] = --n_cut_nodes + Index;
        for(int e : g[u]) {
            block_cut_tree.add_edge({bcc_node_id[u], bcc_edge_id[e]});
        }
    }
    return {bcc_edge_id, bcc_node_id, block_cut_tree};
}
template <bool Index> tuple<vector<int>, vector<int>, graph<0, edge, Index>> build_block_cut_tree(graph<0, edge, Index>& g) {
    auto [cut_node, bccs] = find_bccs(g);
    return build_block_cut_tree(g, cut_node, bccs);
}
