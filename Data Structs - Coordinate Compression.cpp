#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<T> compress(const vector<T>& a) {
    vector<T> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<T> compressed = a;
    for(T& val : compressed) {
        val = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
    }
    return compressed;
}
