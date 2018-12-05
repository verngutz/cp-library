#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>&;
template <typename T> vector<int> left_nearest_smaller_values(const vector<T>& a, f<bool(T, T)> cmp = less<T>()) {
    stack<int> s;
    vector<int> nearest_smaller_to(a.size());
    for(int i = 0; i < a.size(); i++) {
        while(not s.empty() and !cmp(a[i], a[s.top()])) {
            s.pop();
        }
        nearest_smaller_to[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    return nearest_smaller_to;
}
template <typename T> vector<int> right_nearest_smaller_values(const vector<T>& a, f<bool(T, T)>& cmp = less<T>()) {
    stack<int> s;
    vector<int> nearest_smaller_to(a.size());
    for(int i = a.size() - 1; i >= 0; i--) {
        while(not s.empty() and !cmp(a[i], a[s.top()])) {
            s.pop();
        }
        nearest_smaller_to[i] = s.empty() ? a.size() - 1 : s.top() - 1;
        s.push(i);
    }
    return nearest_smaller_to;
}
