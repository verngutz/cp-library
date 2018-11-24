#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100'000;
struct edge { int u, v, w; };
vector<edge> adj[N+1];
void link(int u, int v, int w) {
    adj[u].push_back({u, v, w});
    adj[v].push_back({v, u, w});
}
bool vis[N+1];
int d[N+1];
edge p[N+1];
ll mcst(int s, int n = N) {
    fill(vis, vis + n + 1, false);
    fill(d, d + n + 1, -1);
    d[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({-d[s], s});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(const edge& e : adj[u]) {
                if(not vis[e.v] and (d[e.v] > e.w or d[e.v] == -1)) {
                    d[e.v] = e.w;
                    p[e.v] = e;
                    pq.push({-d[e.v], e.v});
                }
            }
        }
    }
    ll cost = 0;
    for(int i = 1; i <= n; i++) if(i != s) {
        cost += p[i].w;
    }
    return cost;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        link(u, v, w);
    }
    mcst(1);
    return 0;
}
