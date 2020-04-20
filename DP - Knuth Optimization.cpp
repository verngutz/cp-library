#include <bits/stdc++.h>
using namespace std;
// DP on substrings: optimum way to form binary tree from array of size N
// cost of putting elements from index i to index j into one subtree is c(i, j)
// solve recurrence of form OPT(i, j) = min i <= k <= j OPT(i, k) + OPT(k + 1, j) + c(i, j)
// argmin(i, j - 1) <= argmin(i, j) <= argmin(i + 1, j) must be satisfied
// alternatively, c must satisfy for all w <= x <= y <= z:
// quadrangle inequality: c(w, y) + c(x, z) <= c(w, z) + c(x, y)
// monotonicity: c(x, y) <= c(w, z)
// runs in O(N^2) assuming c is constant time
template <typename T, size_t N> T knuth(int n, const function<T(int, int)>& c) {
    static T opt[N + 2][N + 2];
    static int arg[N + 2][N + 2];
    memset(opt, 0, sizeof opt);
    for(int len = 1; len <= n; len++) {
        for(int i = 1, j; (j = i + len - 1) <= n; i++) {
            if(len == 1) {
                opt[i][j] = c(i, j), arg[i][j] = i;
            } else {
                for(int k = arg[i][j - 1]; k <= arg[i + 1][j]; k++) {
                    if(k == arg[i][j - 1] or opt[i][j] > opt[k + 1][j] + c(i, j)) {
                        arg[i][j] = k, opt[i][j] = opt[k + 1][j] + c(i, j);
                    }
                }
            }
        }
    }
    return opt[1][n];
}
