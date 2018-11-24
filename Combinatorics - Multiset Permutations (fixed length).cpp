#include <bits/stdc++.h>
using namespace std;
#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Permutations.cpp"
// #define N 100'000
// #define LEN 20
modint C(vector<int> occ, int max_len) {
    static modint mem[N+1][LEN+1] = {};
    function<modint(int, int)> C = [&](int i, int len) {
        modint& ans = mem[i+1][len];
        if(ans == 0) {
            if(i == -1) {
                ans = f(max_len - len); // len == 0 ? fac[max_len] : 0;
            } else {
                ans = 0;
                for(int c = 0; c <= min(len, occ[i]); c++) {
                    ans += C(i - 1, len - c) * f_inv(c);
                }
            }
        }
        return ans;
    };
    return C(occ.size() - 1, max_len);
}
