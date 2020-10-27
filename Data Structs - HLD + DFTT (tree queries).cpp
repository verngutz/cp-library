#include <bits/stdc++.h>
#include "Data Structs - HLD + DFTT.cpp"
using namespace std;
enum struct tree_t { node_values, edge_values };
template <tree_t T, typename SegmentTree, typename TEdge, bool Index> struct tree_queries {
    SegmentTree& st;
    flat_tree<TEdge, Index> ft;
    vector<int> &head, &p, &d, &f;
    tree_queries(SegmentTree& st, graph<0, TEdge, Index>& g, int root = Index)
    : st(st), ft(g, root), head(ft.head), p(ft.p), d(ft.d), f(ft.f) {}
    void node_update(int u, typename SegmentTree::DeltaType value) {
        st.update(d[u], value);
        st.update(f[u], value);
    }
    void edge_update(int u, int v, typename SegmentTree::DeltaType value) {
        node_update(d[u] > d[v] ? u : v, value);
    }
    typename SegmentTree::Type subtree_query(int root) {
        return st.query(d[root], f[root], true);
    }
    void subtree_update(int root, typename SegmentTree::DeltaType value) {
        st.update(d[root], f[root], value, true);
    }
    typename SegmentTree::Type anc_path_query(int from, int to) {
        if(from == to) return st.m.identity;
        if(d[from] < d[to]) swap(from, to);
        if(head[from] == head[to]) {
            return st.query(d[to] + 1, d[from], true);
        } else {
            return st.m.combine(st.query(d[head[from]], d[from], true), anc_path_query(p[head[from]], to));
        }
    }
    void anc_path_update(int from, int to, typename SegmentTree::DeltaType value) {
        if(from == to) return;
        if(d[from] < d[to]) swap(from, to);
        if(head[from] == head[to]) {
            st.update(d[to] + 1, d[from], value, true);
        } else {
            st.update(d[head[from]], d[from], value, true), anc_path_update(p[head[from]], to, value);
        }
    }
    typename SegmentTree::Type path_query(int u, int v) {
        int l = ft.lca(u, v);
        typename SegmentTree::Type ans = st.m.combine(anc_path_query(u, l), anc_path_query(l, v));
        return T == tree_t::node_values ? st.m.combine(ans, st.query(d[l])) : ans;
    }
    void path_update(int u, int v, typename SegmentTree::DeltaType value) {
        int l = ft.lca(u, v);
        anc_path_update(u, l, value), anc_path_update(l, v, value);
        if(T == tree_t::node_values) st.update(d[l], value);
    }
};
