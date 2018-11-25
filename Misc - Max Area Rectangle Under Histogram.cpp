#include <bits/stdc++.h>
#include "Data Structs - All Nearest Smaller Values.cpp"
using namespace std;
using ll = long long;
ll max_histogram_rectangle(const vector<ll>& a) {
    vector<int> left_nearest = left_nearest_smaller_values(a);
    vector<int> right_nearest = right_nearest_smaller_values(a);
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans = max(ans, a[i] * (right_nearest[i] - left_nearest[i] + 1));
    }
    return ans;
}
