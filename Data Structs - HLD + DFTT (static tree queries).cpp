#include <bits/stdc++.h>
#include "Data Structs - HLD + DFTT.cpp"
#include "Data Structs - Sparse Table.cpp"
using namespace std;
enum struct tree_t { node_values, edge_values };
template <tree_t Type, typename T, bool Index> struct tree_queries {
    sparse_table<T> st;
    flat_tree<TEdge, Index> ft;
    vector<int> &head, &p, &d, &f;
    tree_queries(graph<0, TEdge, Index>& g, const monoid<T>& m, int root = Index)
    : st(st), ft(g, root), head(ft.head), p(ft.p), d(ft.d), f(ft.f), st(make_st(m)) {}
    sparse_table<T> make_st(const monoid<T>& m) {

    }
    T subtree_query(int root) {
        return st.query(d[root], f[root], true);
    }
    T anc_path_query(int from, int to) {
        if(from == to) return st.m.identity;
        if(d[from] < d[to]) swap(from, to);
        if(head[from] == head[to]) {
            return st.query(d[to] + 1, d[from], true);
        } else {
            return st.m.combine(st.query(d[head[from]], d[from], true), anc_path_query(p[head[from]], to));
        }
    }
    T path_query(int u, int v) {
        int l = ft.lca(u, v);
        T ans = st.m.combine(anc_path_query(u, l), anc_path_query(l, v));
        return Type == tree_t::node_values ? st.m.combine(ans, st.query(d[l])) : ans;
    }
};
template <typename T, bool Index> struct node_valued_tree_queries {

};
template <typename T, 
    void node_update(int u, typename SegmentTree::DeltaType value) {
        st.update(d[u], value);
        st.update(f[u], value);
    }
    void edge_update(int u, int v, typename SegmentTree::DeltaType value) {
        node_update(d[u] > d[v] ? u : v, value);
    }