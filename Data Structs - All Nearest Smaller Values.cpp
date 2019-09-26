#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Cmp = decltype(less<T>())>
vector<int> nsv(const vector<T>& a, int L, int R, int d, Cmp&& cmp = less<T>()) {
    static_assert(is_convertible<decltype(cmp), function<bool(T, T)>>::value, "cmp must be bool(T, T)");
    vector<int> s, nearest_smaller_to(a.size());
    for(int i = L; i != R; i += d) {
        while(not s.empty() and not cmp(a[s.back()], a[i])) {
            s.pop_back();
        }
        nearest_smaller_to[i] = s.empty() ? L - d : s.back();
        s.push_back(i);
    }
    return nearest_smaller_to;
}
template <typename T, typename Cmp = decltype(less<T>())>
vector<int> lnsv(const vector<T>& a, Cmp&& cmp = less<T>()) {
    return nsv(a, 0, a.size(), 1, cmp);
}
template <typename T, typename Cmp = decltype(less<T>())>
vector<int> rnsv(const vector<T>& a, Cmp&& cmp = less<T>()) {
    return nsv(a, a.size() - 1, -1, -1, cmp);
}
