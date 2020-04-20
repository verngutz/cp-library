#include <bits/stdc++.h>
#include "Graph Structures - Edge (unweighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <bool Index> vector<vector<int>> find_sccs(graph<1, edge, Index>& g) {
    vector<int> vis(g.adj.size()), low(g.adj.size()), scc_stack, in_scc_stack(g.adj.size());
    vector<vector<int>> sccs = {};
    int timer = 1;
    function<void(int, int)> dfs = [&](int u) {
        visit[u] = low[u] = timer++;
        scc_stack.push_back(u);
        in_scc_stack[u] = true;
        for(int e : g[u]) {
            if(not vis[g(e).v]) {
                dfs(g(e).v);   
            }
            if(in_scc_stack[g(e).v]) {
                low[u] = min(low[u], low[g(e).v]);
            }
        }
        if(vis[u] == low[u]) {
            sccs.push_back(vector<int>());
            do {
                sccs.back().push_back(scc_stack.back());
                in_scc_stack[scc_stack.back()] = false;
                scc_stack.pop_back();
            } while(sccs.back().back() != u);
        }
    };
    for(int u = Index; u < g.adj.size(); u++) if(not vis[u]) {
        dfs(u, 0);
    }
    return sccs;
}
