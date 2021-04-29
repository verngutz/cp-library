#include <bits/stdc++.h>
#include "Graph Structures - Edge (unweighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename TEdge, bool Index> pair<vector<int>, vector<vector<int>>> find_2eccs(graph<0, TEdge, Index>& g) {
    vector<int> vis(g.adj.size()), low(g.adj.size()), cut_edge(g.edges.size()), s;
    vector<vector<int>> _2eccs = {};
    int timer = 1;
    function<void(int, int)> dfs = [&](int u, int from) {
        vis[u] = low[u] = timer++;
        s.push_back(u);
        for(int e : g[u]) {
            if(not vis[g(e).v]) {
                dfs(g(e).v, e & ~1);
                if(vis[u] < low[g(e).v]) {
                    cut_edge[e] = cut_edge[e ^ 1] = true;
                    _2eccs.push_back(vector<int>());
                    do {
                        _2eccs.back().push_back(s.back()), s.pop_back();
                    } while(_2eccs.back().back() != g(e).v);
                }
                low[u] = min(low[u], low[g(e).v]);
            } else if((e & ~1) != from and vis[u] > vis[g(e).v]) {
                low[u] = min(low[u], vis[g(e).v]);
            }
        }
    };
    for(int u = Index; u < g.adj.size(); u++) if(not vis[u]) {
        dfs(u, -1);
        _2eccs.push_back(vector<int>());
        while(not s.empty()) {
            _2eccs.back().push_back(s.back()), s.pop_back();
        }
    }
    return {move(cut_edge), move(_2eccs)};
}
