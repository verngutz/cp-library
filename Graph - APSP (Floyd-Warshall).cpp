#include <bits/stdc++.h>
#define N 500
using namespace std;
using ll = long long;
ll d[N+1][N+1];
int p[N+1][N+1];
void apsp_init(int n) {
    memset(d, -1, sizeof d);
    memset(p, -1, sizeof p);
    for(int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
}
void apsp(int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[i][k] != -1 and d[k][j] != -1 and (d[i][j] > d[i][k] + d[k][j] or d[i][j] == -1)) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    apsp_init(n);
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
        p[u][v] = u;
        p[v][u] = v;
    }
    apsp(n);
}
