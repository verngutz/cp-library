#include <bits/stdc++.h>
#include "Binary Search.cpp"
using namespace std;
using ll = long long;
// NOTE: zero-indexed, returns indices of LIS, not actual sequence
template <typename T> vector<T> LIS(const vector<T>& a) {
    T max_val = accumulate(a.begin(), a.end(), a[0], [](T x, T y) { return max(x, y); });
    vector<int> pre(a.size()), end_id(a.size() + 1);
    vector<T> end_val(a.size() + 1);
    int ans = 0;
    fill(end_val.begin(), end_val.end(), max_val + 1);
    for(int i = 0; i < a.size(); i++) {
        int lis_len = max(1, lt(end_val.begin(), end_val.end(), a[i]) + 1);
        pre[i] = lis_len > 1 ? end_id[lis_len - 1] : -1;
        end_id[lis_len] = i;
        end_val[lis_len] = a[i];
        ans = max(ans, lis_len);
    }
    vector<T> lis;
    for(int cur = end_id[ans]; cur != -1; cur = pre[cur]) {
        lis.push_back(cur);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
