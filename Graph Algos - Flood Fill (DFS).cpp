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
template <typename Can> grid<int> flood(grid<int>& a, Can&& can) {
    static_assert(is_convertible<decltype(can), function<bool(int, int)>>::value, "can must be bool(int, int)");
    grid<int> component(a.n, a.m);
    int component_id = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
        if(0 <= i and i < a.n and 0 <= j and j < a.m and a[i][j] and not component[i][j]) {
            component[i][j] = component_id;
            for(int di = -1; di <= 1; di++) {
                for(int dj = -1; dj <= 1; dj++) {
                    if(can(di, dj)) {
                        dfs(i + di, j + dj);
                    }
                }
            }
        }
    };
    for(int i = 0; i < a.n; i++) {
        for(int j = 0; j < a.m; j++) {
            if(a[i][j] and not component[i][j]) {
                component_id++;
                dfs(i, j);
            }
        }
    }
    return component;
}
