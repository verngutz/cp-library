#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<int> compress(vector<T>& a, int start_index = 1) {
    vector<int> compressed(a.size());
    set<T> values(a.begin(), a.end());
    map<int, int> m;
    for(T x : values) {
        m[x] = start_index++;
    }
    for(int i = 0; i < a.size(); i++) {
        compressed[i] = m[a[i]];
    }
    return compressed;
}
