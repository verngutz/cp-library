#include <bits/stdc++.h>
#include "Data Structs - HLD + DFTT.cpp"
using namespace std;
enum query_t { node, edge };
template <query_t TQuery, typename SegmentTree> struct tree_queries {
    SegmentTree& st;
    flat_tree& ft;
    vector<int> &head, &p, &d, &f;
    tree_queries(SegmentTree& st, flat_tree& ft) : st(st), ft(ft), head(ft.head), p(ft.p), d(ft.d), f(ft.f) {}
    void node_update(int u, typename SegmentTree::DeltaType value) {
        st.update(d[u], value);
        st.update(f[u], value);
    }
    void edge_update(int u, int v, typename SegmentTree::DeltaType value) {
        node_update(d[u] > d[v] ? u : v, value);
    }
    typename SegmentTree::Type subtree_query(int root) {
        return st.query(d[root], f[root]);
    }
    void subtree_update(int root, typename SegmentTree::DeltaType value) {
        st.update(d[root], f[root], value);
    }
    typename SegmentTree::Type anc_path_query(int from, int to) {
        if(d[from] < d[to]) swap(from, to);
        if(head[from] == head[to]) {
            return st.query(d[to] + 1, d[from]);
        } else {
            return st.combine(st.query(d[head[from]], d[from]), anc_path_query(p[head[from]], to));
        }
    }
    void anc_path_update(int from, int to, typename SegmentTree::DeltaType value) {
        if(d[from] < d[to]) swap(from, to);
        if(head[from] == head[to]) {
            st.update(d[to] + 1, d[from], value);
        } else {
            st.update(d[head[from]], d[from], value), anc_path_update(p[head[from]], to, value);
        }
    }
    typename SegmentTree::Type path_query(int u, int v) {
        int l = ft.lca(u, v);
        auto ans = st.combine(anc_path_query(u, l), anc_path_query(l, v));
        return TQuery == node ? st.combine(ans, st.query(d[l], d[l])) : ans;
    }
    void path_update(int u, int v, typename SegmentTree::DeltaType value) {
        int l = ft.lca(u, v);
        anc_path_update(u, l, value), anc_path_update(l, v, value);
        if(TQuery == node) st.update(d[l], d[l], value);
    }
};
