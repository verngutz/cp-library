#include <bits/stdc++.h>
using namespace std;
template <typename T>
long long count_inversions(vector<T>& a, vector<T>& b, int s, int e) {
    if(e - s == 1) {
        return 0;
    } else {
        int m = (s + e) / 2;
        long long ans = count_inversions(a, b, s, m) + count_inversions(a, b, m, e);
        int l_head = s, r_head = m;
        for(int i = s; i < e; i++) {
            if(r_head >= e or (l_head < m and a[l_head] <= a[r_head])) {
                b[i] = a[l_head++];
            } else {
                b[i] = a[r_head++];
                ans += m - l_head;
            }
        }
        for(int i = s; i < e; i++) {
            a[i] = b[i];
        }
        return ans;
    }
}
template <typename T>
long long count_inversions(vector<T>& a) {
    vector<T> b(a.size());
    return count_inversions(a, b, 0, a.size());
}
