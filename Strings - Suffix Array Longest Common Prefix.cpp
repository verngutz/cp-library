#include <bits/stdc++.h>
using namespace std;
vector<int> build_lcp(string& s, vector<int>& sa) {
    vector<int> rank(s.size());
    for(int i = 0; i < s.size(); i++) {
        rank[sa[i]] = i;
    }
    vector<int> lcp(s.size());
    for(int i = 0, k = 0; i < s.size(); i++) {
        if(rank[i] == s.size() - 1) {
            lcp[rank[i]] = k = 0;
        } else {
            int j = sa[rank[i] + 1];
            while(i + k < s.size() and j + k < s.size() and s[i + k] == s[j + k]) {
                k++;
            }
            lcp[rank[i]] = k;
            k = max(0, k - 1);
        }
    }
    return lcp;
}
