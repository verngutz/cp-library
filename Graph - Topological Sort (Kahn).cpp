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
int label[N+1];
void toposort() {
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
        if(outdeg[i] == 0) {
            pq.push(i);
        }
    }
    int cur = n;
    while(not pq.empty()) {
        int v = pq.top(); pq.pop();
        label[v] = cur--;
        for(int u : adj[v]) {
            if(--outdeg[u] == 0) {
                pq.push(u);
            }
        }
    }
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
    toposort();
    for(int i = 1; i <= n; i++) {
        if(i > 1) cout << " ";
        cout << label[i];
    }
    cout << "\n";
    return 0;
}
