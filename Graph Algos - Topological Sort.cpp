#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename TEdge, bool Index> vector<int> toposort(graph<1, TEdge, Index>& g) {
    vector<int> indeg(g.adj.size());
    for(int u = Index; u < g.adj.size(); u++) {
        for(int e : g[u]) {
            indeg[g(e).v]++;
        }
    }
    queue<int> q;
    for(int u = Index; u < g.adj.size(); u++) {
        if(indeg[u] == 0) {
            q.push(u);
        }
    }
    vector<int> ans;
    while(not q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(int e : g[u]) {
            if(--indeg[g(e).v] == 0) {
                q.push(g(e).v);
            }
        }
    }
    return ans;
}