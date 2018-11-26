#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
    int u, v;
    ll c, f;
    edge* reverse;
};
struct graph {
    int n;
    vector<vector<edge*>> adj;
    graph(int n) : n(n), adj(n + 1) {}
    void add_edge(int u, int v, ll c) {
        adj[u].push_back(new edge{u, v, c, 0});
        adj[v].push_back(new edge{v, u, 0, 0, adj[u].back()});
        adj[u].back()->reverse = adj[v].back();
    }
};
ll max_flow(graph& g, int s, int t) {
    vector<int> d(g.n + 1), adj_ptr(g.n + 1);
    vector<edge*> p(g.n + 1);
    auto make_level_graph = [&]() {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(edge* e : g.adj[u]) {
                auto [u, v, c, f, r] = *e;
                if(c - f > 0 and d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    };
    function<bool(int)> find_aug_path = [&](int u) {
        if(u == t) return true;
        for(int& i = adj_ptr[u]; i < g.adj[u].size(); i++) {
            auto [uu, v, c, f, r] = *g.adj[u][i];
            if(d[v] == d[u] + 1 and c - f > 0 and find_aug_path(v)) {
                p[v] = g.adj[u][i];
                return true;
            }
        }
        return false;
    };
    ll ans = 0;
    while(make_level_graph()) {
        fill(adj_ptr.begin(), adj_ptr.end(), 0);
        while(find_aug_path(s)) {
            ll b = numeric_limits<ll>::max();
            for(int v = t; v != s; v = p[v]->u) {
                b = min(b, p[v]->c - p[v]->f);
            }
            for(int v = t; v != s; v = p[v]->u) {
                p[v]->f += b, p[v]->reverse->f -= b;
            }
            ans += b;
        }
    }
    return ans;
}
