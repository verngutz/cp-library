#include <bits/stdc++.h>
#include "Graph - DFS.cpp"
using namespace std;
vector<vector<int>> find_sccs(graph<1>& g) {
    vector<int> visit(g.n + 1, 0), low(g.n + 1);
    int timer = 1;
    stack<int> scc_stack;
    vector<bool> in_scc_stack(g.n + 1, false);
    vector<vector<int>> sccs = {{}};
    dfs(g, [&](int u, int from) {
        visit[u] = low[u] = timer++;
        scc_stack.push(u);
        in_scc_stack[u] = true;
    }, [&](int u, int from) {
        for(auto [i, u, v] : g.adj[u]) {
            if(in_scc_stack[v]) low[u] = min(low[u], low[v]);
        }
        if(visit[u] == low[u]) {
            vector<int> scc;
            do {
                int v = scc_stack.top(); scc_stack.pop();
                in_scc_stack[v] = false;
                scc.push_back(v);
            } while(scc.back() != u);
            sccs.push_back(scc);
        }
    });
    return sccs;
}
graph<1> build_scc_graph(graph<1>& g) {
    vector<vector<int>> sccs = find_sccs(g);
    vector<int> scc_id(g.n + 1);
    for(int i = 1; i < sccs.size(); i++) {
        for(int u : sccs[i]) {
            scc_id[u] = i;
        }
    }
    graph<1> scc_graph(sccs.size() - 1);
    for(int u = 1; u <= g.n; u++) {
        for(auto [i, u, v] : g.adj[u]) {
            if(scc_id[u] != scc_id[v]) {
                scc_graph.add_edge(scc_id[u], scc_id[v]);
            }
        }
    }
    return scc_graph;
}
