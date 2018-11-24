#include "Data Structs - HLD + DFTT.cpp"
int kth_ancestor(flat_tree& f, int u, int k) {
    static vector<int> node_at;
    if(node_at.empty()) {
        node_at.resize(f.n + 1);
        for(int u = 1; u <= f.n; u++) {
            node_at[f.d[u]] = node_at[f.f[u]] = u;
        }
    }
    if(k <= f.d[u] - f.d[f.head[u]]) {
        return node_at[f.d[u] - k];
    } else {
        return kth_ancestor(f, f.p[f.head[u]], k - (f.d[u] - f.d[f.head[u]]) - 1);
    }
}
