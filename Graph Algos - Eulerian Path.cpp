#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename TEdge, bool Index> vector<int> eulerian_path(graph<0, TEdge, Index>& g, bool cycle = true) {
    vector<int> odd_deg;
    for(int u = Index; u < g.adj.size(); u++) {
        if(g[u].size() % 2) {
            odd_deg.push_back(u);
        }
    }
    if(odd_deg.empty() or (not cycle and odd_deg.size() == 2)) {
        vector<bool> used(g.edges.size());
        vector<int> tour, adj_ptr(g.adj.size());
        function<void(int)> dfs = [&](int u) {
            for(int& j = adj_ptr[u]; j < g.adj[u].size(); j++) {
                if(not used[g[u][j]]) {
                    used[g[u][j]] = true;
                    dfs(g(g[u][j]).v);
                }
            }
            tour.push_back(u);
        };
        dfs(odd_deg.empty() ? Index : odd_deg[0]);
        return tour;
    } else {
        return {};
    }
}
