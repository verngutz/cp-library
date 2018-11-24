#include <bits/stdc++.h>
#include "Graph - DFS.cpp"
pair<bool, vector<bool>> bicolor(graph<0>& g) {
    bool can = true;
    vector<bool> color(g.n + 1);
    dfs(g, [&](int u, int from) {
        color[u] = from ? not color[from] : true;
    }, [&](int u, int) {
        for(auto [i, u, v] : g.adj[u]) {
            can &= color[v] != color[u];
        }
    });
    return {can, color};
}
