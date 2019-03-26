#include <bits/stdc++.h>
using namespace std;
// DP on partitions: optimum partition of array of size SIZE into PARTS cells
// cost of putting elements from index i to index j into one cell, the pth one from the left, is c(p, i, j)
// solve recurrence of form OPT(p, j) = min i <= j OPT(p - 1, i - 1) + c(p, i, j)
// change cmp to greater<T>() for maximization
// argmin(p, j) <= argmin(p, j + 1) must be satisfied
// alternatively, c must satisfy for all w <= x <= y <= z and all p:
// quadrangle inequality: c(p, w, y) + c(p, x, z) <= c(p, w, z) + c(p, x, y)
// runs in O(PARTS SIZE lg SIZE) assuming c is constant time
template<typename T, size_t PARTS, size_t SIZE, bool SAVE_SPACE = true>
T dnc(int parts, int n, const function<T(int, int, int)>& c,
function<bool(T, T)> cmp = less<T>(), bool allow_empty = false, T zero = 0) {
    static T opt[SAVE_SPACE ? 2 : (PARTS + 1)][SIZE + 1];
    static int arg[SAVE_SPACE ? 2 : (PARTS + 1)][SIZE + 1];
    function<void(int, int, int, int, int)> make_row = [&](int p, int s, int e, int ks, int ke) {
        if(s > e) return;
        int curr_row = SAVE_SPACE ? p & 1 : p;
        int prev_row = SAVE_SPACE ? (p - 1) & 1 : (p - 1);
        int m = (s + e) / 2;
        for(int k = ks; k <= min(ke, m - not allow_empty); k++) {
            if(k == ks or cmp(opt[prev_row][k] + c(p, k + 1, m), opt[curr_row][m])) {
                opt[curr_row][m] = opt[prev_row][k] + c(p, k + 1, m);
                arg[curr_row][m] = k;
            }
        }
        make_row(p, s, m - 1, ks, arg[curr_row][m]);
        make_row(p, m + 1, e, arg[curr_row][m], ke);
    };
    for(int p = 1; p <= parts; p++) {
        if(p == 1) {
            for(int i = 0; i <= n; i++) {
                opt[SAVE_SPACE ? p & 1 : p][i] = i ? c(p, 1, i) : zero;
            }
        } else {
            make_row(p, 0, n, 0, n);
        }
    }
    return opt[SAVE_SPACE ? parts & 1 : parts][n];
}
