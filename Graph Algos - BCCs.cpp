#include <bits/stdc++.h>
#include "Graph Structures - Edge (unweighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <bool Index> pair<vector<int>, vector<vector<int>>> find_bccs(graph<0, edge, Index>& g) {
    vector<int> vis(g.adj.size()), low(g.adj.size()), cut_node(g.adj.size()), s;
    vector<vector<int>> bccs = {};
    int timer = 1;
    function<void(int, int)> dfs = [&](int u, int from) {
        vis[u] = low[u] = timer++;
        int n_children = 0;
        for(int e : g[u]) {
            if(not vis[g(e).v]) {
                s.push_back(e & ~1);
                dfs(g(e).v, u);
                n_children++;
                if(vis[u] <= low[g(e).v]) {
                    cut_node[u] = true;
                    bccs.push_back(vector<int>());
                    do {
                        bccs.back().push_back(s.back()), s.pop_back();
                    } while(bccs.back().back() != (e & ~1));
                }
                low[u] = min(low[u], low[g(e).v]);
            } else if(g(e).v != from and vis[u] > vis[g(e).v]) {
                s.push_back(e & ~1);
                low[u] = min(low[u], vis[g(e).v]);
            }
        }
        cut_node[u] &= from or n_children > 1;
    };
    for(int u = Index; u < g.adj.size(); u++) if(not vis[u]) {
        dfs(u, 0);
    }
    return {cut_node, bccs};
}
