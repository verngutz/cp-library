#include <bits/stdc++.h>
#define L 500
#define R 500
#define N (L + R)
#define INF 1'000'000'000
using namespace std;
int n_left, n_right, m;
vector<int> adj[L+1];
bool matched[L+1];
int partner[R+1], adj_ptr[L+1], d[L+1];
bool make_level_graph() {
    memset(d, -1, sizeof d);
    queue<int> q;
    for(int u = 1; u <= n_left; u++) {
        if(not matched[u]) {
            d[u] = 0;
            q.push(u);
        }
    }
    bool has_unmatched = false;
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(partner[v] == -1) {
                has_unmatched = true;
            } else if(d[partner[v]] == -1) {
                d[partner[v]] = d[u] + 1;
                q.push(partner[v]);
            }
        }
    }
    return has_unmatched;
}
bool dfs(int u) {
    for(int& i = adj_ptr[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(partner[v] == -1 or (d[partner[v]] == d[u] + 1 and dfs(partner[v]))) {
            partner[v] = u;
            matched[u] = true;
            return true;
        }
    }
    return false;
}
int main() {
    memset(matched, false, sizeof matched);
    memset(partner, -1, sizeof partner);
    cin >> n_left >> n_right >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int max_matching = 0;
    while(make_level_graph()) {
        memset(adj_ptr, 0, sizeof adj_ptr);
        for(int u = 1; u <= n_left; u++) {
            max_matching += not matched[u] and dfs(u);
        }
    }
    cout << max_matching << endl;
}
