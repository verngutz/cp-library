#include <bits/stdc++.h>
using namespace std;
int ceil_pow2(int x) {
    return x <= 1 ? 1 : 2 << __lg(x - 1);
}
template <typename T> struct mergesort_tree {
    vector<T> values;
    vector<vector<pair<int, int>>> cascade;
    mergesort_tree(const vector<T>& a): values(a), cascade(ceil_pow2(ssize(a)), {{0, 0}}) {
        vector<pair<int, int>> sorted(ssize(a));
        for(int i = 0; i < ssize(values); i++) {
            sorted[i] = {values[i], i};
        }
        ranges::sort(values);
        ranges::sort(sorted);
        for(auto& [val, index] : sorted) {
            for(int node = ssize(cascade) + index; node > 1; node >>= 1) {
                auto [prev_L, prev_R] = cascade[node >> 1].back();
                cascade[node >> 1].push_back({prev_L + ((node & 1) ^ 1), prev_R + (node & 1)});
            }
        }
    }
    int count_leq(int L, int R, bool inclusive, const T& val) {
        int fraction = ranges::upper_bound(values, val) - values.begin();
        return count_leq(1, 0, ssize(cascade), L, R + inclusive, fraction);
    }
private:
    int count_leq(int node, int s, int e, int L, int R, int fraction) {
        if(L <= s and e <= R) {
            return fraction;
        } else if(R <= s or e <= L) {
            return 0;
        } else {
            int m = midpoint(s, e);
            auto [frac_L, frac_R] = cascade[node][fraction];
            return count_leq(node << 1, s, m, L, R, frac_L) + count_leq((node << 1) | 1, m, e, L, R, frac_R);
        }
    }
};