#include <bits/stdc++.h>
#include "Combinatorics - Permutations.cpp"
using namespace std;
template <typename T = mint> T C(const vector<int>& occ, int max_len) {
    static vector<vector<T>> mem(occ.size(), vector<T>(max_len + 1));
    function<T(int, int)> C = [&](int i, int len) {
        T& ans = mem[i + 1][len];
        if(ans == 0) {
            if(i == -1) {
                ans = fact<T>(max_len - len); // len == 0 ? fac[max_len] : 0;
            } else {
                ans = 0;
                for(int c = 0; c <= min(len, occ[i]); c++) {
                    ans += C(i - 1, len - c) * fact_inv<T>(c);
                }
            }
        }
        return ans;
    };
    return C(occ.size() - 1, max_len);
}
