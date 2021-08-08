#include <bits/stdc++.h>
#include "Graph Structures - Edge (weighted).cpp"
#include "Data Structs - Binary Lift.cpp"
#include "Data Structs - Monoid.cpp"
using namespace std;
template <typename T, bool Index> struct wedge_binary_lift : public binary_lift<wedge<T>, Index> {
    vector<vector<T>> pvals;
    const monoid<T> m;
    wedge_binary_lift(graph<0, wedge<T>, Index>& g, const monoid<T>& m) 
    : binary_lift<wedge<T>, Index>(g), pvals(g.adj.size()), m(m) {
        dfs(g, [&](dfs_params<wedge<T>>& params) {
            params.root = Index;
            params.pre_edge = [&](wedge<T>& e) {
                pvals[e.v].resize(__lg(this->depth[e.v]) + 1);
                pvals[e.v][0] = e.w;
                build_pvals(e.v);
            };
        });
    }
    void build_pvals(int u) {
        for(int pow2 = 1; pow2 <= __lg(this->depth[u]); pow2++) {
            pvals[u][pow2] = m.combine(pvals[u][pow2 - 1], pvals[this->p[u][pow2 - 1]][pow2 - 1]);
        }
    }
    T anc_path_query(int u, int k) {
        return k == 0 ? m.identity : m.combine(
            pvals[u][__lg(k)], 
            anc_path_query(this->p[u][__lg(k)], k ^ (1 << __lg(k)))
        );
    }
    T path_query(int u, int v) {
        int l = this->lca(u, v);
        return m.combine(
            anc_path_query(u, this->depth[u] - this->depth[l]),
            anc_path_query(v, this->depth[v] - this->depth[l])
        );
    }
};
