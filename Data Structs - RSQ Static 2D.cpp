#include <bits/stdc++.h>
// #define N 1000
int n, m;
long long a[N+1][N+1], s[N+1][N+1];
void build() {
    memset(s, 0, sizeof s);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
}
long long query(int r1, int c1, int r2, int c2) {
    return s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1];
}
