#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
vector<int> eulerian_path(graph<0>& g, bool cycle = true) {
    vector<int> odd_deg;
    for(int u = 1; u <= g.n; u++) {
        if(g.adj[u].size() % 2) {
            odd_deg.push_back(u);
        }
    }
    if(odd_deg.empty() or (not cycle and odd_deg.size() == 2)) {
        vector<bool> used(g.edges.size());
        vector<int> tour, adj_ptr(g.n + 1);
        function<void(int)> dfs = [&](int u) {
            for(int& j = adj_ptr[u]; j < g.adj[u].size(); j++) {
                auto [uu, v, i] = g.adj[u][j];
                if(not used[i]) {
                    used[i] = true;
                    dfs(v);
                }
            }
            tour.push_back(u);
        };
        dfs(odd_deg.empty() ? 1 : odd_deg[0]);
        return tour;
    } else {
        return {};
    }
}
