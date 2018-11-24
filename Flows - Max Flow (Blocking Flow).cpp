#include <bits/stdc++.h>
#define N 500
#define INF 1'000'000'000
using namespace std;
int n, m, s, t;
vector<int> adj[N+1];
int c[N+1][N+1], f[N+1][N+1], adj_ptr[N+1], d[N+1], p[N+1];
bool make_level_graph() {
    memset(d, -1, sizeof d);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(c[u][v] - f[u][v] > 0 and d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d[t] != -1;
}
bool dfs(int u) {
    if(u == t) return true;
    for(int& i = adj_ptr[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(d[v] == d[u] + 1 and c[u][v] - f[u][v] > 0 and dfs(v)) {
            p[v] = u;
            return true;
        }
    }
    return false;
}
bool find_aug_path() {
    memset(p, -1, sizeof p);
    p[s] = 0;
    return dfs(s);
}
void add_edge(int u, int v, int capacity) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] += capacity;
}
int main() {
    memset(c, 0, sizeof c);
    memset(f, 0, sizeof f);
    cin >> n >> s >> t >> m;
    for(int i = 0; i < m; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        add_edge(u, v, capacity);
    }
    int max_flow_value = 0;
    while(make_level_graph()) {
        memset(adj_ptr, 0, sizeof adj_ptr);
        while(find_aug_path()) {
            int b = INF;
            for(int v = t, u = p[v]; v != s; v = u, u = p[v]) {
                b = min(b, c[u][v] - f[u][v]);
            }
            for(int v = t, u = p[v]; v != s; v = u, u = p[v]) {
                f[u][v] += b;
                f[v][u] -= b;
            }
            max_flow_value += b;
        }
    }
    cout << max_flow_value << endl;
}
