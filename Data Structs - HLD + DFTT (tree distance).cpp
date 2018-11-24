#include "Data Structs - HLD + DFTT.cpp"
int dist(flat_tree& f, int u, int v) {
    return f.depth[u] + f.depth[v] - 2 * f.depth[f.lca(u, v)];
}
