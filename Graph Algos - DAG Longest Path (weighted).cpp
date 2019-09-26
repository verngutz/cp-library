#include <bits/stdc++.h>
#include "Graph Structures - Edge (weighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
using ll = long long;
template <typename T, bool Index> pair<vector<T>, vector<int>> longest_path(graph<1, wedge<T>, Index>& g,
const vector<int>& roots = vector<int>(),
const vector<T>& node_weight = vector<T>()) {
    vector<T> opt(g.adj.size(), -1);
    vector<int> arg(g.adj.size(), -1);
    auto weight = [&](int u) { return node_weight.empty() ? 0 : node_weight[u]; };
    function<T(int)> longest_path = [&](int u) {
        if(opt[u] == -1) {
            opt[u] = weight(u);
            for(int e : g[u]) {
                if(opt[u] < weight(u) + g(e).w + longest_path(g(e).v)) {
                    opt[u] = weight(u) + g(e).w + longest_path(g(e).v);
                    arg[u] = e;
                }
            }
        }
        return opt[u];
    };
    if(roots.empty()) {
        for(int u = Index; u < g.adj.size(); u++) {
            longest_path(u);
        }
    } else {
        for(int root : roots) {
            longest_path(root);
        }
    }
    return {opt, arg};
}
