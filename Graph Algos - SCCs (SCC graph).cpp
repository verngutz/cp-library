#include "Graph Algos - SCCs.cpp"
template <bool Index> pair<vector<vector<int>>, graph<1, edge, Index>> build_scc_graph(graph<1, edge, Index>& g) {
    vector<vector<int>> sccs = find_sccs(g);
    vector<int> scc_id(g.adj.size());
    for (int i = 0; i < sccs.size(); i++) {
        for (int u : sccs[i]) {
            scc_id[u] = i + Index;
        }
    }
    graph<1, edge, Index> scc_graph(sccs.size());
    for (int e = 0; e < g.edges.size(); e++) {
        if (scc_id[g(e).u] != scc_id[g(e).v]) {
            scc_graph.add_edge({scc_id[g(e).u], scc_id[g(e).v]});
        }
    }
    return {move(sccs), move(scc_graph)};
}
