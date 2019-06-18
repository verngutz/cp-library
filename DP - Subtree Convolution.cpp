#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
#include "Graph - DFS.cpp"
using namespace std;

template <typename T, size_t N, size_t K>
T tree_convolution(T zero, const function<T(T, T)>& add, const function<T(T, T)>& mul, graph<0>& g, int k) {
    vector<int> p(g.n + 1), sz(g.n + 1, 1), topological_order;
    dfs(g, [](int, int) {}, [&](int u, int from) {
        p[u] = from;
        topological_order.push_back(u);
    });
    static T OPT[N+1][K+1];
    fill_n(&OPT[0][0], (N+1)*(K+1), zero);
    for(int v : topological_order) {
        // write base cases here
    }
    topological_order.pop_back();
    for(int v : topological_order) {
        int u = p[v];
        for(int k_par = min(k, sz[v] + sz[u]); k_par >= 0; k_par--) {
            T ans = zero;
            for(int k_sub = max(0, k_par - sz[u]); k_sub <= min(sz[v], k_par); k_sub++) {
                // write convolution formula here
                ans = add(ans, mul(OPT[u][k_par - k_sub], OPT[v][k_sub]));
            }
            OPT[u][k_par] = ans;
        }
        sz[u] += sz[v];
    }
    return OPT[1][k];
}
