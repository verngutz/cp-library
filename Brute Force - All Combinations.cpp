#include <bits/stdc++.h>
using namespace std;
template <typename F> void combinations(int n, int k, const F& f) {
    static_assert(is_convertible<decltype(f), function<void(vector<int>&)>>::value);
    function<void(int, vector<int>&)> rb = [&](int i, vector<int>& c) {
        if(c.size() == k) {
            f(c);
        } else if(i < n) {
            if(n - i + c.size() > k) {
                rb(i + 1, c);
            }
            c.push_back(i);
            rb(i + 1, c);
            c.pop_back();
        }
    };
    static vector<int> c;
    c.reserve(k);
    rb(0, c);
}
