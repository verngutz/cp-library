#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> fwht(const vector<T>& a) {
    int n = a.size();
    if(n == 1) {
        return a;
    } else {
        vector<T> s(a.begin(), a.begin() + n / 2), e(a.begin() + n / 2, a.end());
        vector<T> ha = fwht(s), hb = fwht(e), ans(n);
        for(int j = 0; j < n; j++) {
            ans[j] = ha[j % (n / 2)] + (j < n / 2 ? 1 : -1) * hb[j % (n / 2)];
        }
        return ans;
    }
}
template <typename T> vector<T> xor_convolution(const vector<T>& A, const vector<T>& B) {
    int n = A.size();
    vector<T> a = fwht(A), b = fwht(B), c(n);
    for(int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }
    vector<T> ans = fwht(c);
    transform(ans.begin(), ans.end(), ans.begin(), [n](T x) { return x / n; });
    return ans;
}
