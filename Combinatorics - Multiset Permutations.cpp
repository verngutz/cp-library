#include <bits/stdc++.h>
using namespace std;
#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Permutations.cpp"
modint C(vector<int> occ) {
    modint ans = f(accumulate(occ.begin(), occ.end(), 0));
    for(int x : occ) {
        ans *= f_inv(x);
    }
    return ans;
}
