#include <bits/stdc++.h>
#include "Graph - DFS.cpp"
using namespace std;
struct flat_tree {
    int n;
    vector<int> p, depth, head, d, f;
    flat_tree(graph<0>& g) : n(g.n), p(n + 1), depth(n + 1), head(n + 1), d(n + 1), f(n + 1) {
        vector<int> size(n + 1, 1);
        dfs(g, [&](int, int) {}, [&](int u, int from) {
            for(adj_edge& e : g.adj[u]) if(e.v != from) {
                size[u] += size[e.v];
                if(g.adj[u][0].v == from or size[e.v] > size[g.adj[u][0].v]) {
                    swap(e, g.adj[u][0]);
                }
            }
        });
        int timer = 1;
        dfs(g, [&](int u, int from) {
            p[u] = from;
            depth[u] = from ? depth[from] + 1 : 0;
            head[u] = from and u == g.adj[from][0].v ? head[from] : u;
            d[u] = timer++;
        }, [&](int u, int from) {
            f[u] = timer++;
        });
    }
    int lca(int u, int v) {
        if(head[u] == head[v]) {
            return depth[u] < depth[v] ? u : v;
        } else {
            return depth[head[u]] < depth[head[v]] ? lca(u, p[head[v]]) : lca(p[head[u]], v);
        }
    }
};
