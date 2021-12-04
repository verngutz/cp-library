#include <bits/stdc++.h>
using namespace std;
template <typename T> T evaluate(const vector<T>& p, const T& n) {
    T ans = 0;
    for(auto x = p.rbegin(); x != p.rend(); x++) {
        ans *= n;
        ans += *x;
    }
    return ans;
}
