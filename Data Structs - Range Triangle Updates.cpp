#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
// const int N = 5000;
long long a[N+1][N+1];
void add(int n, int i, int j, long long v) {
    if(1 <= i and i <= n and 1 <= j and j <= n) {
        a[i][j] += v;
    }
}
void update(int n, int i, int j, int r, long long v = 1) {
    add(n, i, j, v);
    add(n, i, j + 1, -v);
    add(n, i + r, j, -v);
    add(n, i + r, j + r + 1, v);
    add(n, i + r + 1, j + 1, v);
    add(n, i + r + 1, j + r + 1, -v);
}
void sum(int n, int si, int sj, int di, int dj) {
    for(int i = si; i <= n; i++) {
        for(int j = sj; j <= n; j++) {
            a[i][j] += a[i-di][j-dj];
        }
    }
}
void resolve(int n) {
    sum(n, 1, 2, 0, 1);
    sum(n, 2, 1, 1, 0);
    sum(n, 2, 2, 1, 1);
}
template <typename Function>
void proc(int n, const Function& f) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<void(int, int)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "proc 'f' must be void(int, int)");
#endif
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            f(i, j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    while(q--) {
        int i, j, r, v;
        cin >> i >> j >> r >> v;
        update(n, i, j, r, v);
    }
    resolve(n);
    proc(n, [&](int i, int j) {
        cout << a[i][j];
        if(j == n) cout << endl;
        else cout << " ";
    });
    return 0;
}
