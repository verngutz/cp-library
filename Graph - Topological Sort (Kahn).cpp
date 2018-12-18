#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
using ll = long long;
vector<int> toposort(graph<1>& g) {
    vector<int> indeg(g.n + 1);
    for(int u = 1; u <= g.n; u++) {
        for(auto [u, v, i] : g.adj[u]) {
            indeg[v]++;
        }
    }
    queue<int> q;
    for(int u = 1; u <= g.n; u++) {
        if(indeg[u] == 0) {
            q.push(u);
        }
    }
    vector<int> ans;
    while(not q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(auto [u, v, i] : g.adj[u]) {
            if(--indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    return ans;
}
