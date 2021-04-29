#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
#include "Graph Algos - DFS.cpp"
using namespace std;
template <typename TEdge, bool Index> bool has_eulerian_path(graph<0, TEdge, Index>& g, bool cycle, vector<int>& odd_deg) {
    for(int u = Index; u < g.adj.size(); u++) {
        if((g[u].size() - count_if(g[u].begin(), g[u].end(), [&](int e) { return g(e).v == u; })) % 2) {
            odd_deg.push_back(u);
        }
    }
    return odd_deg.empty() or (not cycle and odd_deg.size() == 2);
}
template <typename TEdge, bool Index> bool has_eulerian_path(graph<1, TEdge, Index>& g, bool cycle, vector<int>& odd_deg) {
    vector<int> outdeg(g.adj.size()), indeg(g.adj.size());
    for(const TEdge& e : g.edges) {
        outdeg[e.u]++;
        indeg[e.u]++;
    }
    bool can = true;
    for(int u = Index; u < g.adj.size() and can; u++) {
        can &= abs(outdeg[u] - indeg[u]) <= 1;
    }
    for(int u = Index; u < g.adj.size() and can; u++) {
        if(outdeg[u] - indeg[u] == 1) {
            odd_deg.push_back(u);
        }
    }
    for(int u = Index; u < g.adj.size() and can; u++) {
        if(indeg[u] - outdeg[u] == 1) {
            odd_deg.push_back(u);
        }
    }
    return can and (odd_deg.empty() or (not cycle and odd_deg.size() == 2));
}
template <bool Directed, typename TEdge, bool Index> vector<int> eulerian_path(graph<Directed, TEdge, Index>& g, bool cycle = true) {
    if(vector<int> odd_deg; has_eulerian_path(g, cycle, odd_deg)) {
        vector<bool> used(g.edges.size());
        vector<int> tour, adj_ptr(g.adj.size());
        function<void(int)> dfs = [&](int u) {
            for(int& j = adj_ptr[u]; j < g.adj[u].size(); j++) {
                int e = g[u][j];
                if(not used[e] and not used[e ^ (not Directed)]) {
                    used[e] = used[e ^ (not Directed)] = true;
                    dfs(g(e).v);
                    tour.push_back(e);
                }
            }
        };
        dfs(odd_deg.empty() ? Index : odd_deg[0]);
        if(tour.size() == (g.edges.size() >> not Directed)) {
            reverse(tour.begin(), tour.end());
            return move(tour);
        } else {
            return {};
        }
    } else {
        return {};
    }
}
