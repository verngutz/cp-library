#include <bits/stdc++.h>
using namespace std;
bool hori(int di, int dj) { return abs(di) == 0 and abs(dj) == 1; }
bool vert(int di, int dj) { return abs(di) == 1 and abs(dj) == 0; }
bool diag(int di, int dj) { return abs(di) == 1 and abs(dj) == 1; }
bool can(int di, int dj) { return hori(di, dj) or vert(di, dj) or diag(di, dj); }
template <typename signature> using f = const function<signature>&;
void flood(vector<vector<bool>>& a, int i, int j, f<bool(int, int)> can, f<void(int, int)> f) {
    static vector<vector<bool>> vis(a.size(), vector<bool>(a[0].size()));
    if(a[i][j] and not vis[i][j]) {
        f(i, j);
        vis[i][j] = true;
        for(int di = -1; di <= 1; di++) {
            for(int dj = -1; dj <= 1; dj++) {
                if(can(di, dj)) {
                    flood(a, i + di, j + dj, can, f);
                }
            }
        }
    }
}
void block_boundaries(vector<vector<bool>>& a, int n, int m) {
    for(int i = 0; i <= n + 1; i++) {
        a[i][0] = a[i][m + 1] = false;
    }
    for(int i = 0; i <= m + 1; i++) {
        a[0][i] = a[n + 1][i] = false;
    }
}
