#include <bits/stdc++.h>
#include "Data Structs - Grid.cpp"
using namespace std;
vector<pair<int, int>> hori = {{0, -1}, {0, 1}};
vector<pair<int, int>> vert = {{-1, 0}, {1, 0}};
vector<pair<int, int>> diag = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
vector<pair<int, int>>& operator+=(vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
};
vector<pair<int, int>> operator+(vector<pair<int, int>> a, const vector<pair<int, int>>& b) {
    return a += b;
};
grid<int> flood(grid<int>& a, const vector<pair<int, int>>& moves) {
    grid<int> component(a.n, a.m);
    int component_id = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
        if(0 <= i and i < a.n and 0 <= j and j < a.m and a[i][j] and not component[i][j]) {
            component[i][j] = component_id;
            for(auto [di, dj] : moves) {
                dfs(i + di, j + dj);
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
