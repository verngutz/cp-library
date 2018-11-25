#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
template <typename T> void build(int n, int m, const vector<vector<T>>& a) {
    vector<vector<T>> s(n, vector<vector<T>>(m));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
}
template <typename T> T query(const vector<vector<T>>& s, int r1, int c1, int r2, int c2) {
    return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
}
