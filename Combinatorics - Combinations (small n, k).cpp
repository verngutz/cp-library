#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
#include "Math - Modular Arithmetic.cpp"
modint C(int n, int k) {
    static vector<vector<modint>> c;
    while(c.size() <= n) {
        vector<modint> row;
        int m = c.size();
        for(int k = 0; k <= m; k++) {
            row.push_back(k == 0 or k == m ? 1 : c[m-1][k] + c[m-1][k-1]);
        }
        c.push_back(row);
    }
    return c[n][k];
}
#endif
