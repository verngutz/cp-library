#include <bits/stdc++.h>
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename T> concept GraftFunc = is_convertible_v<T, f<void(int, int)>>;
template <typename T> concept PruneFunc = is_convertible_v<T, f<void(int, int)>>;
template <typename T> concept RootFunc = is_convertible_v<T, f<void(int)>>;
template <bool Directed, typename TEdge, bool Index, GraftFunc Graft, PruneFunc Prune, RootFunc Root>
void tree_rerooting(graph<Directed, TEdge, Index>& g, const Graft& graft, const Prune& prune, const Root& pos_node) {
    dfs(g, [&](dfs_params<TEdge>& p) {
        p.pos_edge = [&](TEdge& e) {
            graft(e.u, e.v);
        };
    });
    dfs(g, [&](dfs_params<TEdge>& p) {
        p.pre_edge = [&](TEdge& e) {
            prune(e.u, e.v);
            graft(e.v, e.u);
        };
        p.pos_node = pos_node;
        p.pos_edge = [&](TEdge& e) {
            prune(e.v, e.u);
            graft(e.u, e.v);
        };
    });
}