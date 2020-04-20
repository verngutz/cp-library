#include <bits/stdc++.h>
using namespace std;
vector<int> build_suffix_array(string& s) {
    s += '$';
    vector<int> sa(s.size()), c(s.size()), new_c(s.size());
    for(int i = 0; i < s.size(); i++) {
        sa[i] = i;
        c[i] = s[i];
    }
    stable_sort(sa.begin(), sa.end(), [&](int i, int j) { return c[i] < c[j]; });
    for(int k = 0; 1 << k <= s.size(); k++) {
        int jump = 1 << k;
        stable_sort(sa.begin(), sa.end(), [&](int i, int j) {
            return c[i] < c[j] or (c[i] == c[j] and c[i + jump] < c[j + jump]);
        });
        new_c[sa[0]] = 0;
        for(int i = 1; i < s.size(); i++) {
            new_c[sa[i]] = new_c[sa[i - 1]] + (c[sa[i]] != c[sa[i - 1]] or c[sa[i] + jump] != c[sa[i - 1] + jump]);
        }
        swap(c, new_c);
    }
    return sa;
}
