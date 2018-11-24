#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
template <bool Directed>
vector<int> bfs(graph<Directed>& g, int s, const function<void(int)>& f = [](int) {}) {
    vector<int> d(g.n + 1, -1), p(g.n + 1);
    d[s] = 0, p[s] = -1;
    queue<int> q;
    q.push(s);
    while(not q.empty()) {
        int u = q.front(); q.pop();
        f(u);
        for(auto [i, u, v] : g.adj[u]) {
            if(d[v] == -1) {
                d[v] = d[u] + 1, p[v] = u;
                q.push(v);
            }
        }
    }
    return d;
}
