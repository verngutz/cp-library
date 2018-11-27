#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// NOTE: one-indexed
struct edge {
    int u, v;
    ll w, c, f;
    edge* reverse;
};
struct graph {
    bool has_negative_edge;
    int n;
    vector<vector<edge*>> adj;
    graph(int n) : has_negative_edge(false), n(n), adj(n + 1) {}
    void add_edge(int u, int v, ll w, ll c) {
        has_negative_edge |= w < 0;
        adj[u].push_back(new edge{u, v, w, c, 0});
        adj[v].push_back(new edge{v, u, -w, 0, 0, adj[u].back()});
        adj[u].back()->reverse = adj[v].back();
    }
};
pair<ll, ll> min_cost_flow(graph& g, int s, int t, ll flow_limit = numeric_limits<ll>::max()) {
    vector<bool> vis(g.n + 1);
    vector<ll> d(g.n + 1), pot(g.n + 1);
    vector<edge*> p(g.n + 1);
    auto find_aug_path = [&]() {
        fill(vis.begin(), vis.end(), false);
        fill(d.begin(), d.end(), numeric_limits<ll>::max());
        d[s] = 0;
        priority_queue<pair<ll, int>> pq;
        pq.push({-d[s], s});
        while(not pq.empty()) {
            int u = pq.top().second; pq.pop();
            if(not vis[u]) {
                vis[u] = true;
                for(edge* e : g.adj[u]) {
                    auto [u, v, w, c, f, r] = *e;
                    if(not vis[v] and c - f > 0 and d[v] > d[u] + pot[u] + w - pot[v]) {
                        p[v] = e, d[v] = d[u] + pot[u] + w - pot[v];
                        pq.push({-d[v], v});
                    }
                }
            }
        }
        return d[t] < numeric_limits<ll>::max();
    };
    if(g.has_negative_edge) {
        fill(pot.begin(), pot.end(), numeric_limits<ll>::max());
        pot[s] = 0;
        for(int i = 0; i < g.n - 1; i++) {
            for(int u = 1; u <= g.n; u++) {
                for(edge* e : g.adj[u]) {
                    if(e->c and pot[e->u] < numeric_limits<ll>::max()) {
                        pot[e->v] = min(pot[e->v], pot[e->u] + e->w);
                    }
                }
            }
        }
    }
    ll flow = 0, cost = 0;
    while(flow < flow_limit and find_aug_path()) {
        ll b = flow_limit - flow;
        for(int v = t; v != s; v = p[v]->u) {
            b = min(b, p[v]->c - p[v]->f);
        }
        for(int v = t; v != s; v = p[v]->u) {
            p[v]->f += b, p[v]->reverse->f -= b;
            cost += b * p[v]->w;
        }
        flow += b;
        for(int i = 1; i <= g.n; i++) {
            pot[i] += d[i];
        }
    }
    return {flow, cost};
}
