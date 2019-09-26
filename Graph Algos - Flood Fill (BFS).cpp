#include <bits/stdc++.h>
#include "Data Structs - Grid.cpp"
using namespace std;
template <typename signature> using f = const function<signature>;
f<bool(int, int)> hori = [](int di, int dj) { return abs(di) == 0 and abs(dj) == 1; };
f<bool(int, int)> vert = [](int di, int dj) { return abs(di) == 1 and abs(dj) == 0; };
f<bool(int, int)> diag = [](int di, int dj) { return abs(di) == 1 and abs(dj) == 1; };
f<bool(int, int)> operator||(f<bool(int, int)>& f1, f<bool(int, int)>& f2) {
    return [&](int di, int dj) { return f1(di, dj) or f2(di, dj); };
}
template <typename Can> grid<int> flood(grid<int>& a, vector<pair<int, int>>& s, Can&& can) {
    static_assert(is_convertible<decltype(can), function<bool(int, int)>>::value, "can must be bool(int, int)");
    grid<int> d(a.n, a.m, -1);
    for(auto [i, j] : s) {
        d[i][j] = 0;
    }
    queue<pair<int, int>> q(s.begin(), s.end());
    while(not q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for(int di = -1; di <= 1; di++) {
            for(int dj = -1; dj <= 1; dj++) {
                int ni = i + di, nj = j + dj;
                if(0 <= ni and ni < a.n and 0 <= nj and nj < a.m and a[ni][nj] and d[ni][nj] == -1 and can(di, dj)) {
                    d[ni][nj] = d[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
    return d;
}
