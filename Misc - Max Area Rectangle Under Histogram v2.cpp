#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll max_histogram_rectangle(vector<ll>& a, int n) {
    stack<int> s;
    ll ans = 0;
    a[n] = 0;
    for(int i = 0; i <= n; i++) {
        while(not s.empty() and a[s.top()] >= a[i]) {
            int k = s.top();
            s.pop();
            ans = max(ans, a[k] * (s.empty() ? i : i - s.top() - 1));
        }
        s.push(i);
    }
    return ans;
}
