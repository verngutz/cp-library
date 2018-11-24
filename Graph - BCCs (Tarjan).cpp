#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
pair<vector<bool>, vector<vector<int>>> find_bccs(graph<0>& g) {
    vector<int> visit(g.n + 1), low(g.n + 1), edge_to(g.n + 1);
    int timer = 1;
    vector<bool> cut_node(g.n + 1, false);
    stack<int> s;
    vector<vector<int>> bccs = {{}};
    function<void(int, int)> dfs = [&](int u, int from) {
        visit[u] = low[u] = timer++;
        int dfs_children = 0;
        for(auto [i, u, v] : g.adj[u]) {
            if(not visit[v]) {
                s.push(i);
                edge_to[v] = i;
                dfs(v, u);
                dfs_children++;
                low[u] = min(low[u], low[v]);
                cut_node[u] = cut_node[u] or (visit[u] <= low[v] and from);
                if(visit[u] <= low[v]) {
                    bccs.push_back(vector<int>());
                    do {
                        bccs.back().push_back(s.top()); s.pop();
                    } while(bccs.back().back() != i);
                }
            } else if(edge_to[u] != i) {
                low[u] = min(low[u], visit[v]);
            }
        }
        cut_node[u] = cut_node[u] or (not from and dfs_children > 1);
    };
    for(int u = 1; u <= g.n; u++) {
        if(not visit[u]) {
            dfs(u, 0);
        }
    }
    return {cut_node, bccs};
}
pair<vector<int>, graph<0>> build_block_cut_tree(graph<0>& g, vector<bool>& cut_node, vector<vector<int>>& bccs) {
    int n_cut_nodes = count(cut_node.begin(), cut_node.end(), true);
    vector<int> bcc_id(g.edges.size() + 1);
    for(int i = 1; i < bccs.size(); i++) {
        for(int e : bccs[i]) {
            bcc_id[e] = n_cut_nodes + i;
        }
    }
    graph<0> block_cut_tree(n_cut_nodes + bccs.size() - 1);
    for(int u = 1; u <= g.n; u++) {
        for(auto [i, u, v] : g.adj[u]) {
            if(cut_node[u]) {
                block_cut_tree.add_edge(u, bcc_id[i]);
            }
        }
    }
    return {bcc_id, block_cut_tree};
}
pair<vector<int>, graph<0>> build_block_cut_tree(graph<0>& g) {
    auto [cut_node, bccs] = find_bccs(g);
    return build_block_cut_tree(g, cut_node, bccs);
}
