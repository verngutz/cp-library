#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>;
f<bool(int, int)> hori = [](int di, int dj) { return abs(di) == 0 and abs(dj) == 1; };
f<bool(int, int)> vert = [](int di, int dj) { return abs(di) == 1 and abs(dj) == 0; };
f<bool(int, int)> diag = [](int di, int dj) { return abs(di) == 1 and abs(dj) == 1; };
f<bool(int, int)> operator||(f<bool(int, int)>& f1, f<bool(int, int)>& f2) {
    return [&](int di, int dj) { return f1(di, dj) or f2(di, dj); };
}
vector<vector<int>> flood(vector<vector<int>>& a, int si, int sj,
f<bool(int, int)>& can, f<void(int, int)>& f = [](int, int) {}) {
    vector<vector<int>> d(a.size(), vector<int>(a[0].size(), -1));
    d[si][sj] = 0;
    queue<pair<int, int>> q({{si, sj}});
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
    return d;
}
