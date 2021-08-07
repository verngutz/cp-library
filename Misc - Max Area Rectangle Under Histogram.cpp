#include <bits/stdc++.h>
#include "Data Structs - All Nearest Smaller Values.cpp"
using namespace std;
template <typename T> T max_histogram_rectangle(const vector<T>& a) {
    vector<int> left_nearest = lnsv(a);
    vector<int> right_nearest = rnsv(a);
    T ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans = max(ans, a[i] * (right_nearest[i] - left_nearest[i] - 1));
    }
    return ans;
}
