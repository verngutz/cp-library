#include <bits/stdc++.h>
#include "Combinatorics - Permutations.cpp"
using namespace std;
template <typename T = mint> T C(const vector<int>& occ) {
    T ans = fact<T>(accumulate(occ.begin(), occ.end(), 0));
    for(int x : occ) {
        ans *= fact_inv<T>(x);
    }
    return ans;
}
