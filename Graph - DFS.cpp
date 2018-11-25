#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
template <bool Directed> void dfs(graph<Directed>& g,
const function<void(int, int)>& pre = [](int u, int from) {},
const function<void(int, int)>& pos = [](int u, int from) {}) {
    vector<bool> vis(g.n + 1);
    function<void(int, int)> dfs = [&](int u, int from) {
        vis[u] = true;
        pre(u, from);
        for(auto [i, u, v] : g.adj[u]) {
            if(not vis[v]) {
                dfs(v, u);
            }
        }
        pos(u, from);
    };
    for(int u = 1; u <= g.n; u++) {
        if(not vis[u]) {
            dfs(u, 0);
        }
    }
}
