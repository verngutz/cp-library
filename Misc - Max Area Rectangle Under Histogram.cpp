#include <bits/stdc++.h>
#include "Data Structs - All Nearest Smaller Values.cpp"
using namespace std;
using ll = long long;
ll max_histogram_rectangle(vector<ll>& a) {
    vector<int> lim_left = find_lim_left(a);
    vector<int> lim_right = find_lim_right(a);
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans = max(ans, a[i] * (lim_right[i] - lim_left[i] + 1));
    }
    return ans;
}
