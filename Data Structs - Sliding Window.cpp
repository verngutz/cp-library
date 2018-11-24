#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
#define N 100'000
using namespace std;
typedef long long ll;
struct elem { int t, v; };
// NOTE: one-indexed
template <typename T, typename Function>
vector<T> sliding_window(vector<T>& a, int k, const Function& cmp) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<bool(T, T)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "sliding_window 'cmp' must be bool(T, T)");
#endif
    vector<T> ans;
    deque<elem> window;
    for(int i = 1; i <= a.size(); i++) {
        while(not window.empty() and !cmp(window.back().v, a[i])) {
            window.pop_back();
        }
        window.push_back({i, a[i]});
        while(window.front().t <= i - k) {
            window.pop_front();
        }
        if(i >= k) {
            ans.push_back(window.front().v);
        }
    }
    return ans;
}
template <typename T>
vector<T> sliding_window(vector<T>& a, int k) { return sliding_window(a, k, [](T x, T y){ return x > y; }); }
