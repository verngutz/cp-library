#include <bits/stdc++.h>
#include "Data Structs - Euler Tour Tree.cpp"
#include "Data Structs - Sparse Table.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
template <typename TEdge, bool Index> struct ett_lca {
    using pii = pair<int, int>;
    flat_tree<TEdge, Index> ft;
    vector<int> &depth, &d, &f, &component;
    sparse_table<pii> st;
    ett_lca(graph<0, TEdge, Index>& g, int root = Index) 
    : ft(g, root), depth(ft.depth), d(ft.d), f(ft.f), component(ft.component), st(make_st()) {}
    sparse_table<pii> make_st() {
        vector<pii> depthed_tour(ft.tour.size());
        for(int i = 0; i < ft.tour.size(); i++) {
            depthed_tour[i] = {depth[ft.tour[i]], ft.tour[i]};
        }
        return sparse_table<pii>(depthed_tour, {{lim<int>::max(), 0}, [](const pii& x, const pii& y) { return min(x, y); }});
    }
    int lca(int u, int v) {
        return u == v ? u : (f[u] < d[v] ? st.query(f[u], d[v], true) : st.query(f[v], d[u], true)).second;
    }
};
