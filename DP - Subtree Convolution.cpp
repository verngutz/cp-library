#include <bits/stdc++.h>
#include "Graph Structures - Edge (unweighted).cpp"
#include "Graph Structures - Incidence List.cpp"
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename T, int N, int K, bool Index, typename Add = decltype(plus<T>()), typename Mul = decltype(multiplies<T>())>
T(*tree_convolution(graph<0, edge, Index>& g, bool connected, T zero = 0, Add&& add = plus<T>(), Mul&& mul = multiplies<T>()))[K+1] {
    vector<int> p(g.adj.size()), sz(g.adj.size(), 1), topological_order;
    dfs(g, [&](dfs_params<edge>& psetter) {
        psetter.pos_node = [&](int u) { topological_order.push_back(u); };
        psetter.pos_edge = [&](edge& e) { p[e.v] = e.u; };
    });
    static T opt[N+1][K+1];
    fill_n(&opt[0][0], (N+1)*(K+1), zero);
    for(int v : topological_order) {
        // base cases
    }
    topological_order.pop_back();
    for(int v : topological_order) {
        int u = p[v];
        for(int k_par = min(K, sz[v] + sz[u]); k_par >= connected; k_par--) {
            T ans = zero;
            for(int k_sub = max(0, k_par - sz[u]); k_sub <= min(sz[v], k_par - connected); k_sub++) {
                ans = add(ans, mul(opt[u][k_par - k_sub], opt[v][k_sub] /* + cost(u, v) */));
            }
            opt[u][k_par] = ans;
        }
        sz[u] += sz[v];
    }
    return opt;
}
