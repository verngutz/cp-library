#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#include "Math - Modular Arithmetic.cpp"
template <typename T = mint> T C(int n, int k) {
    static vector<vector<T>> c;
    while(c.size() <= n) {
        vector<T> row;
        int m = c.size();
        for(int k = 0; k <= m; k++) {
            row.push_back(k == 0 or k == m ? 1 : c[m - 1][k] + c[m - 1][k - 1]);
        }
        c.push_back(row);
    }
    return c[n][k];
}
#endif
