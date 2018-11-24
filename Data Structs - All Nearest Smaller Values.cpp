#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
using ll = long long;
template <typename Function>
vector<int> find_lim_left(vector<ll>& a, const Function& cmp) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<bool(ll, ll)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "find_lim_left 'cmp' must be bool(ll, ll)");
#endif
    stack<int> s;
    vector<int> lim(a.size());
    for(int i = 0; i < a.size(); i++) {
        while(not s.empty() and !cmp(a[i], a[s.top()])) {
            s.pop();
        }
        lim[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    return lim;
}
vector<int> find_lim_left(vector<ll>& a) { return find_lim_left(a, [](ll x, ll y) { return x < y; }); }
template <typename Function>
vector<int> find_lim_right(vector<ll>& a, const Function& cmp) {
#ifdef DEBUG
    using actual_type = typename callable_traits<Function>::function_type;
    using expected_type = typename callable_traits<bool(ll, ll)>::function_type;
    static_assert(is_same<actual_type, expected_type>::value, "find_lim_right 'cmp' must be bool(ll, ll)");
#endif
    stack<int> s;
    vector<int> lim(a.size());
    for(int i = a.size() - 1; i >= 0; i--) {
        while(not s.empty() and !cmp(a[i], a[s.top()])) {
            s.pop();
        }
        lim[i] = s.empty() ? a.size() - 1 : s.top() - 1;
        s.push(i);
    }
    return lim;
}
vector<int> find_lim_right(vector<ll>& a) { return find_lim_right(a, [](ll x, ll y) { return x < y; }); }
