#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>;
f<bool(int, int)> hori = [](int di, int dj) { return abs(di) == 0 and abs(dj) == 1; };
f<bool(int, int)> vert = [](int di, int dj) { return abs(di) == 1 and abs(dj) == 0; };
f<bool(int, int)> diag = [](int di, int dj) { return abs(di) == 1 and abs(dj) == 1; };
f<bool(int, int)> operator||(f<bool(int, int)>& f1, f<bool(int, int)>& f2) {
    return [&](int di, int dj) { return f1(di, dj) or f2(di, dj); };
}
vector<vector<int>> flood(vector<vector<int>>& a, f<bool(int, int)>& can, f<void(int, int, int, int)>& f) {
    int n = a.size() - 2, m = a[0].size() - 2;
    vector<vector<int>> component(n + 2, vector<int>(m + 2));
    int component_id = 0;
    function<void(int, int, int, int)> dfs = [&](int i, int j, int from_i, int from_j) {
        if(a[i][j] and not component[i][j]) {
            f(i, j, from_i, from_j);
            component[i][j] = component_id;
            for(int di = -1; di <= 1; di++) {
                for(int dj = -1; dj <= 1; dj++) {
                    if(can(di, dj)) {
                        dfs(i + di, j + dj, i, j);
                    }
                }
            }
        }
    };
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(not component[i][j]) {
                component_id++;
                dfs(i, j, 0, 0);
            }
        }
    }
    return component;
}
