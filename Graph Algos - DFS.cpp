#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename T> using f = function<T>;
template <typename TEdge> struct dfs_params {
    f<void(int)> pre_node = [](int) -> void {};
    f<void(int)> pos_node = [](int) -> void {};
    f<void(TEdge&)> pre_edge = [](TEdge&) -> void {};
    f<void(TEdge&)> pos_edge = [](TEdge&) -> void {};
    bool reuse_previous_components = false;
    int root = -1;
};
template <bool Directed, typename TEdge, bool Index, typename TParamsetter = f<void(dfs_params<TEdge>&)>>
vector<int>& dfs(graph<Directed, TEdge, Index>& g, const TParamsetter& psetter = [](dfs_params<TEdge>&) {}) {
    static_assert(is_convertible<decltype(psetter), f<void(dfs_params<TEdge>&)>>::value);
    dfs_params<TEdge> params;
    psetter(params);
    static vector<int> component(g.adj.size());
    static int c = 0;
    if(not params.reuse_previous_components) {
        component.resize(g.adj.size());
        fill(component.begin(), component.end(), 0);
        c = 0;
    }
    function<void(int, int)> dfs = [&](int u, int c) {
        component[u] = c;
        params.pre_node(u);
        for(int e : g[u]) if(not component[g(e).v]) {
            params.pre_edge(g(e)), dfs(g(e).v, c), params.pos_edge(g(e));
        }
        params.pos_node(u);
    };
    if(params.root == -1) {
        for(int u = Index; u < g.adj.size(); u++) if(not component[u]) {
            dfs(u, ++c);
        }
    } else {
        dfs(params.root, ++c);
    }
    return component;
}
