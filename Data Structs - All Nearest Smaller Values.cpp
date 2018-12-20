#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>&;
template <typename T> vector<int> left_nearest_smaller_values(const vector<T>& a, f<bool(T, T)> cmp = less<T>()) {
    stack<int> s;
    vector<int> nearest_smaller_to(a.size());
    for(int i = 0; i < a.size(); i++) {
        while(not s.empty() and !cmp(a[s.top()], a[i])) {
            s.pop();
        }
        nearest_smaller_to[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return nearest_smaller_to;
}
template <typename T> vector<int> right_nearest_smaller_values(const vector<T>& a, f<bool(T, T)>& cmp = less<T>()) {
    stack<int> s;
    vector<int> nearest_smaller_to(a.size());
    for(int i = a.size() - 1; i >= 0; i--) {
        while(not s.empty() and !cmp(a[s.top()], a[i])) {
            s.pop();
        }
        nearest_smaller_to[i] = s.empty() ? a.size() : s.top();
        s.push(i);
    }
    return nearest_smaller_to;
}
