#include <bits/stdc++.h>
#include "Graph - DFS.cpp"
using namespace std;
struct binary_lift {
    vector<int> lg, depth;
    vector<vector<int>> p;
    binary_lift(graph<0>& g) : lg(g.n + 1), depth(g.n + 1), p(g.n + 1) {
        lg[0] = -1, lg[1] = 0;
        for(int i = 2; i <= g.n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        dfs(g, [&](int u, int from) {
            if(from) {
                p[u].push_back(from);
                depth[u] = depth[from] + 1;
                build_ancestors(u);
            }
        });
    }
    void build_ancestors(int u) {
        for(int pow2 = 1; pow2 <= lg[depth[u]]; pow2++) {
            p[u].push_back(p[p[u][pow2 - 1]][pow2 - 1]);
        }
    }
    int kth_ancestor(int u, int k) {
        return k == 0 ? u : kth_ancestor(p[u][lg[k & -k]], k - (k & -k));
    }
    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        v = kth_ancestor(v, depth[v] - depth[u]);
        for(int pow2 = lg[depth[u]]; pow2 >= 0; pow2--) {
            if((1 << pow2) <= depth[u] and p[u][pow2] != p[v][pow2]) {
                u = p[u][pow2], v = p[v][pow2];
            }
        }
        return u == v ? u : p[u][0];
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};
