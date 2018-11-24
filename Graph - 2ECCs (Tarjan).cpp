#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
pair<vector<bool>, vector<vector<int>>> find_2eccs(graph<0>& g) {
    vector<int> visit(g.n + 1), low(g.n + 1), edge_to(g.n + 1);
    int timer = 1;
    vector<bool> cut_edge(g.edges.size(), false);
    stack<int> s;
    vector<vector<int>> _2eccs = {{}};
    function<void(int, int)> dfs = [&](int u, int from) {
        visit[u] = low[u] = timer++;
        s.push(u);
        for(auto& e : g.adj[u]) {
            int i = e.i, u = e.u, v = e.v;
            if(not visit[v]) {
                edge_to[v] = i;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                cut_edge[i] = cut_edge[i] or (visit[u] < low[v]);
                if(visit[u] < low[v]) {
                    _2eccs.push_back(vector<int>());
                    do {
                        _2eccs.back().push_back(s.top()); s.pop();
                    } while(_2eccs.back().back() != v);
                }
            } else if(edge_to[u] != i) {
                low[u] = min(low[u], visit[v]);
            }
        }
    };
    for(int u = 1; u <= g.n; u++) {
        if(not visit[u]) {
            dfs(u, 0);
            _2eccs.push_back(vector<int>());
            while(not s.empty()) {
                _2eccs.back().push_back(s.top()); s.pop();
            }
        }
    }
    return {cut_edge, _2eccs};
}
pair<vector<int>, graph<0>> build_bridge_tree(graph<0>& g, vector<bool>& cut_edge, vector<vector<int>>& _2eccs) {
    vector<int> _2ecc_id(g.n + 1);
    for(int i = 1; i < _2eccs.size(); i++) {
        for(int u : _2eccs[i]) {
            _2ecc_id[u] = i;
        }
    }
    graph<0> bridge_tree(_2eccs.size() - 1);
    for(int u = 1; u <= g.n; u++) {
        for(auto [i, u, v] : g.adj[u]) {
            if(cut_edge[i]) {
                bridge_tree.add_edge(_2ecc_id[u], _2ecc_id[v]);
            }
        }
    }
    return {_2ecc_id, bridge_tree};
}
pair<vector<int>, graph<0>> build_bridge_tree(graph<0>& g) {
    auto [cut_edge, _2eccs] = find_2eccs(g);
    return build_bridge_tree(g, cut_edge, _2eccs);
}
