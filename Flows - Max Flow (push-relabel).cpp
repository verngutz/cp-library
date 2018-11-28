#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// WARNING: do not add self-loops to the graph,
// or push-relabel gets stuck pushing excess flow from a node to itself over and over
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
    vector<int> height(g.n + 1), counter(2 * g.n);
    vector<ll> excess(g.n + 1);
    vector<bool> active(g.n + 1);
    queue<int> q;
    height[s] = g.n;
    for(edge* e : g.adj[s]) {
        e->f += e->c, e->reverse->f -= e->c;
        excess[e->v] += e->c, excess[s] -= e->c;
        if(excess[e->v] and not active[e->v] and e->v != s and e->v != t) {
            q.push(e->v), active[e->v] = true;
        }
    }
    auto discharge = [&](int u) {
        for(int i = 0; i < g.adj[u].size() and excess[u]; i++) {
            edge* e = g.adj[u][i];
            if(height[u] > height[e->v] and e->c - e->f > 0) {
                ll d = min(excess[u], e->c - e->f);
                e->f += d, e->reverse->f -= d;
                excess[e->v] += d, excess[u] -= d;
                if(excess[e->v] and not active[e->v] and e->v != s and e->v != t) {
                    q.push(e->v), active[e->v] = true;
                }
            }
        }
    };
    auto relabel = [&](int u) {
        if(counter[height[u]] == 1) {
            for(int i = 1; i <= g.n; i++) {
                if(i != s and height[i] >= height[u]) {
                    counter[height[i]]--;
                    height[i] = max(height[i], g.n + 1);
                    counter[height[i]]++;
                }
            }
        } else {
            counter[height[u]]--;
            height[u] = 2 * g.n - 1;
            for(edge* e : g.adj[u]) {
                if(e->c - e->f > 0) {
                    height[u] = min(height[u], height[e->v] + 1);
                }
            }
            counter[height[u]]++;
        }
    };
    while(not q.empty()) {
        int u = q.front(); q.pop(), active[u] = false;
        discharge(u);
        if(excess[u] and not active[u]) {
            relabel(u);
            q.push(u), active[u] = true;
        }
    }
    return excess[t];
}
