#include <bits/stdc++.h>
#define N 500
#define INF 1'000'000'000
using namespace std;
using ll = long long;
int n, m, s, t;
ll flow_limit;
struct edge {
    int u, v;
    ll w, c, f;
    edge* reverse;
};
vector<edge*> adj[N+1];
ll pot[N+1];
bool vis[N+1];
ll d[N+1];
edge* p[N+1];
bool sssp() {
    fill(vis, vis + n + 1, false);
    fill(d, d + n + 1, -1);
    d[s] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({-d[s], s});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(edge* e : adj[u]) {
                ll new_d = d[u] + pot[u] + e->w - pot[e->v];
                if(not vis[e->v] and e->c - e->f > 0 and (d[e->v] > new_d or d[e->v] == -1)) {
                    d[e->v] = new_d;
                    p[e->v] = e;
                    pq.push({-d[e->v], e->v});
                }
            }
        }
    }
    return d[t] != -1;
}
void add_edge(int u, int v, ll w, ll c) {
    adj[u].push_back(new edge{u, v, w, c, 0});
    adj[v].push_back(new edge{v, u, -w, 0, 0});
    adj[u].back()->reverse = adj[v].back();
    adj[v].back()->reverse = adj[u].back();
}
int main() {
    cin >> n >> s >> t >> m >> flow_limit;
    for(int i = 0; i < m; i++) {
        int u, v, w, capacity;
        cin >> u >> v >> w >> capacity;
        add_edge(u, v, w, capacity);
    }
    ll max_flow_cost = 0;
    ll max_flow_value = 0;
    memset(pot, 0, sizeof pot);
    while(max_flow_value < flow_limit and sssp()) {
        ll b = INF;
        for(int v = t; v != s; v = p[v]->u) {
            b = min(b, p[v]->c - p[v]->f);
        }
        b = min(b, flow_limit - max_flow_value);
        for(int v = t; v != s; v = p[v]->u) {
            p[v]->f += b;
            p[v]->reverse->f -= b;
            max_flow_cost += b * p[v]->w;
        }
        max_flow_value += b;
        for(int i = 0; i <= n; i++) {
            pot[i] += d[i];
        }
    }
}
