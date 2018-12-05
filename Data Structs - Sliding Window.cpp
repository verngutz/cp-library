#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
template <typename T> vector<T> sliding_window(const vector<T>& a, int k, const function<bool(T, T)>& cmp = less<T>()) {
    vector<T> ans;
    deque<pair<int, T>> window;
    for(int i = 1; i <= a.size(); i++) {
        while(not window.empty() and not cmp(window.back().second, a[i])) {
            window.pop_back();
        }
        window.push_back({i, a[i]});
        while(window.front().first <= i - k) {
            window.pop_front();
        }
        if(i >= k) {
            ans.push_back(window.front().v);
        }
    }
    return ans;
}
