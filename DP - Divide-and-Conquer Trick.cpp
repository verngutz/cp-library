#include <bits/stdc++.h>
using namespace std;
// DP on partitions: optimum partition of array of size SIZE into PARTS cells
// cost of putting elements from index i to index j into one cell is c(i, j)
// solve recurrence of form OPT(p, j) = min j < i OPT(p - 1, i) + c(i, j)
// argmin(p, j) <= argmin(p, j + 1) must be satisfied
// runs in O(PARTS SIZE lg SIZE) assuming c is constant time
template<typename T, size_t PARTS, size_t SIZE>
T dnc(int parts, int n, const function<T(int, int)>& c) {
    static T opt[PARTS + 1][SIZE + 1];
    static int arg[PARTS + 1][SIZE + 1];
    function<void(int, int, int, int, int)> make_row = [&](int p, int s, int e, int ks, int ke) {
        if(s > e) return;
        int m = (s + e) / 2;
        for(int k = ks; k <= min(ke, m - 1); k++) {
            if(k == ks or opt[p][m] > opt[p - 1][k] + c(k + 1, m)) {
                arg[p][m] = k, opt[p][m] = opt[p - 1][k] + c(k + 1, m);
            }
        }
        make_row(p, s, m - 1, ks, arg[p][m]);
        make_row(p, m + 1, e, arg[p][m], ke);
    };
    for(int p = 1; p <= parts; p++) {
        if(p == 1) {
            for(int i = 0; i <= n; i++) {
                opt[p][i] = c(1, i);
            }
        } else {
            make_row(p, 0, n, 0, n);
        }
    }
    return opt[parts][n];
}
