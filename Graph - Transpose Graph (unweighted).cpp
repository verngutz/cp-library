#include "Graph - Adjacency List (unweighted).cpp"
graph<1> transpose(graph<1>& g) {
    graph<1> t(g.n);
    for(int u = 1; u <= g.n; u++) {
        for(auto [i, u, v] : g.adj[u]) {
            t.add_edge(v, u);
        }
    }
    return t;
}
