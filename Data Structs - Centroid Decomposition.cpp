#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
void centroid_decomposition(graph<0>& g,
const function<void(int, vector<int>&, vector<bool>&)>& process_component) {
    vector<int> subtree_size(g.n + 1), max_subtree_size(g.n + 1), component;
    vector<bool> in_centroid_tree(g.n + 1);
    function<void(int, int)> dfs = [&](int u, int from) {
        component.push_back(u);
        subtree_size[u] = 1;
        max_subtree_size[u] = 0;
        for(auto [u, v, i] : g.adj[u]) {
            if(v != from and not in_centroid_tree[v]) {
                dfs(v, u);
                subtree_size[u] += subtree_size[v];
                max_subtree_size[u] = max(max_subtree_size[u], subtree_size[v]);
            }
        }
    };
    for(int i = 1; i <= g.n; i++) {
        while(not in_centroid_tree[i]) {
            dfs(i, 0);
            for(int u : component) {
                max_subtree_size[u] = max(max_subtree_size[u], int(component.size()) - subtree_size[u]);
            }
            int centroid = *min_element(component.begin(), component.end(), [&](int u, int v) {
                return max_subtree_size[u] < max_subtree_size[v];
            });
            in_centroid_tree[centroid] = true;
            process_component(centroid, component, in_centroid_tree);
            component.clear();
        }
    }
}
