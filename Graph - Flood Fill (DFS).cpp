#include <bits/stdc++.h>
using namespace std;
bool hori(int di, int dj) { return abs(di) == 0 and abs(dj) == 1; }
bool vert(int di, int dj) { return abs(di) == 1 and abs(dj) == 0; }
bool diag(int di, int dj) { return abs(di) == 1 and abs(dj) == 1; }
bool can(int di, int dj) { return hori(di, dj) or vert(di, dj) or diag(di, dj); }
template <typename signature> using f = const function<signature>&;
void flood(vector<vector<bool>>& a, f<bool(int, int)> can, f<void(int, int)> f) {
    int n = a.size() - 2, m = a[0].size() - 2;
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
    function<void(int, int)> dfs = [&](int i, int j) {
        if(a[i][j] and not vis[i][j]) {
            f(i, j);
            vis[i][j] = true;
            for(int di = -1; di <= 1; di++) {
                for(int dj = -1; dj <= 1; dj++) {
                    if(can(di, dj)) {
                        dfs(i + di, j + dj);
                    }
                }
            }
        }
    };
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(not vis[i][j]) {
                dfs(i, j);
            }
        }
    }
}
