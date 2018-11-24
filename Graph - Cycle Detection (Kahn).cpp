#include <bits/stdc++.h>
#define N 100'000
using namespace std;
using ll = long long;
int n, m;
vector<int> adj[N+1];
int outdeg[N+1];
void link(int u, int v) {
    adj[v].push_back(u);
    outdeg[u]++;
}
bool cyclic() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(outdeg[i] == 0) {
            q.push(i);
        }
    }
    int nvis = 0;
    while(not q.empty()) {
        int v = q.front(); q.pop();
        nvis++;
        for(int u : adj[v]) {
            if(--outdeg[u] == 0) {
                q.push(u);
            }
        }
    }
    return nvis != n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(outdeg, 0, sizeof outdeg);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        link(u, v);
    }
    return 0;
}
