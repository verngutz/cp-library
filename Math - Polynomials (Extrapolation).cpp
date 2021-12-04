#include <bits/stdc++.h>
using namespace std;
template <typename T> T extrapolate(const vector<T>& y, ll n) {
    vector<T> nums(y.size()), Lprod(y.size()), Rprod(y.size());
    iota(nums.rbegin(), nums.rend(), n - int(y.size()) + 1);
    partial_sum(nums.begin(), nums.end(), Lprod.begin(), multiplies<T>());
    partial_sum(nums.rbegin(), nums.rend(), Rprod.rbegin(), multiplies<T>());
    T ans = 0;
    for(int i = 0, sgn = y.size() % 2 ? 1 : -1; i < y.size(); i++, sgn *= -1) {
        ans += y[i] * (i ? Lprod[i - 1] : T(1)) * (i + 1 < y.size() ? Rprod[i + 1] : T(1)) 
                    / (fact(i) * sgn * fact(y.size() - 1 - i));
    }
    return ans;
}
