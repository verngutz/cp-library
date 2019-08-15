#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Cmp = decltype(less<T>())>
vector<int> rnsv(const vector<T>& a, Cmp&& cmp = less<T>()) {
    static_assert(is_convertible<decltype(cmp), function<bool(T, T)>>::value, "cmp must be bool(T, T)");
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
