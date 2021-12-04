#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<T> interpolate(const vector<T>& xs, const vector<T>& ys) {
    vector<T> ans(xs.size() + 1);
    for(int i = 0; i < xs.size(); i++) {
        vector<T> poly = {1};
        for(const T& xj : xs) {
            if(xj != xs[i]) {
                poly *= vector<T>({-xj, 1});
                poly /= (xs[i] - xj);
            }
        }
        ans += (poly *= ys[i]);
    }
    return ans;
}
