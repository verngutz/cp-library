#include <bits/stdc++.h>
using namespace std;
bool hori(int di, int dj) { return abs(di) == 0 and abs(dj) == 1; }
bool vert(int di, int dj) { return abs(di) == 1 and abs(dj) == 0; }
bool diag(int di, int dj) { return abs(di) == 1 and abs(dj) == 1; }
bool can(int di, int dj) { return hori(di, dj) or vert(di, dj) or diag(di, dj); }
template <typename signature> using f = const function<signature>&;
void flood(vector<vector<bool>>& a, int si, int sj, f<bool(int, int)> can, f<void(int, int)> f = [](int, int) {}) {
    vector<vector<int>> d(a.size(), vector<int>(a[0].size(), -1));
    d[si][sj] = 0;
    queue<pair<int, int>> q;
    q.push({si, sj});
    while(not q.empty()) {
        auto [i, j] = q.front(); q.pop();
        f(i, j);
        for(int di = -1; di <= 1; di++) {
            for(int dj = -1; dj <= 1; dj++) {
                int ni = i + di, nj = j + dj;
                if(a[ni][nj] and d[ni][nj] == -1 and can(di, dj)) {
                    d[ni][nj] = d[i][j] + 1;
                    q.push({ni, nj});
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
