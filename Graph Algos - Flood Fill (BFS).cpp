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
grid<int> flood(const grid<int>& a, const vector<pair<int, int>>& s, const vector<pair<int, int>>& moves) {
    grid<int> d(a.n, a.m, lim<int>::max());
    queue<pair<int, int>> q;
    for(auto [i, j] : s) {
        d[i][j] = 0;
        q.push({i, j});
    }
    while(not q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for(auto [di, dj] : moves) {
            int ni = i + di, nj = j + dj;
            if(0 <= ni and ni < a.n and 0 <= nj and nj < a.m and a[ni][nj] and d[ni][nj] > d[i][j] + 1) {
                d[ni][nj] = d[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    return d;
}
