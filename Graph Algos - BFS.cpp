#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
template <typename T> using lim = numeric_limits<T>;
template <bool Directed, typename TEdge, bool Index>
pair<vector<int>, vector<int>> bfs(const graph<Directed, TEdge, Index>& g, const vector<int>& s) {
    vector<int> d(g.adj.size(), lim<int>::max()), p(g.adj.size(), -1);
    queue<int> q;
    for(int u : s) {
        d[u] = 0;
        q.push(u);
    }
    while(not q.empty()) {
        int u = q.front(); q.pop();
        for(int e : g[u]) {
            if(d[g(e).v] > d[u] + 1) {
                d[g(e).v] = d[u] + 1, p[g(e).v] = e;
                q.push(g(e).v);
            }
        }
    }
    return {d, p};
}
