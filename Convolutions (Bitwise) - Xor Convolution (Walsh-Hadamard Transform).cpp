#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T>& fwht(vector<T>& a) {
    int n = a.size();
    if(n == 1) {
        return a;
    } else {
        vector<T> s(a.begin(), a.begin() + n / 2), e(a.begin() + n / 2, a.end());
        fwht(s), fwht(e);
        for(int j = 0; j < n; j++) {
            a[j] = s[j % (n / 2)] + (j < n / 2 ? 1 : -1) * e[j % (n / 2)];
        }
        return a;
    }
}
template <typename T> vector<T>& operator^=(vector<T>& a, vector<T>& b) {
    fwht(a);
    if(addressof(a) != addressof(b)) fwht(b);
    assert(a.size() == b.size());
    transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<T>());
    transform(a.begin(), a.end(), a.begin(), [n = a.size()](T x) { return x / n; });
    if(addressof(a) != addressof(b)) fwht(b);
    return a;
}
template <typename T> vector<T> operator^(vector<T> a, vector<T>& b) { return a ^= b; }
