#include <bits/stdc++.h>
#define N 1000
#define MAX_W 1'000'000'000ll
#define INF (N * MAX_W)
using namespace std;
using ll = long long;
struct edge { int u, v, w; };
ll d[N+1];
int p[N+1];
bool neg_cycle[N+1];
void sssp(int s, vector<edge>& edges, int n = N) {
    fill(d, d + n + 1, INF);
    fill(p, p + n + 1, -1);
    d[s] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(edge& e : edges) {
            if(d[e.u] != INF) {
                if(d[e.v] > d[e.u] + e.w) {
                    d[e.v] = d[e.u] + e.w;
                    p[e.v] = e.u;
                }
            }
        }
    }
    fill(neg_cycle, neg_cycle + n + 1, false);
    for(int i = 0; i < n; i++) {
        for(edge& e : edges) {
            if(d[e.u] != INF) {
                if(d[e.v] > d[e.u] + e.w) {
                    d[e.v] = d[e.u] + e.w;
                    neg_cycle[e.v] = true;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sssp(1, edges);
    return 0;
}
