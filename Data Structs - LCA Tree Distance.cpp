template <typename LCA_struct> int dist(LCA_struct& s, int u, int v) {
    return s.depth[u] + s.depth[v] - 2 * s.depth[s.lca(u, v)];
}
