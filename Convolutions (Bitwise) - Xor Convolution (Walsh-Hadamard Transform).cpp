#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
using namespace std;
template <typename T> vector<T>& fwht(vector<T>& a, int s, int e) {
    if(e - s > 1) {
        int m = (s + e) / 2;
        fwht(a, s, m);
        fwht(a, m, e);
        for(int i = s, j = m; i < m; i++, j++) {
            int tmp = a[i] + a[j];
            a[j] = a[i] - a[j], a[i] = tmp;
        }
    }
    return a;
}
template <typename T> vector<T>& fwht(vector<T>& a) {
    return fwht(a, 0, a.size());
}
template <typename T> vector<T>& operator*=(vector<T>& a, vector<T>& b) {
    fwht(a);
    if(addressof(a) != addressof(b)) fwht(b);
    assert(a.size() == b.size());
    transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<T>());
    transform(a.begin(), a.end(), a.begin(), [&](const T& x) { return x / int(a.size()); });
    if(addressof(a) != addressof(b)) {
        fwht(b);
        transform(b.begin(), b.end(), b.begin(), [&](const T& x) { return x / int(b.size()); });
    }
    return fwht(a);
}
template <typename T> vector<T> operator*(vector<T> a, vector<T>& b) { return a *= b; }
template <typename T> vector<T>& operator^=(vector<T>& x, long long y) {
    fwht(x);
    transform(x.begin(), x.end(), x.begin(), [&](T& xi) { return fpow_eq(xi, y) / int(x.size()); });
    return fwht(x);
}
template <typename T> vector<T> operator^(vector<T> x, long long y) { return x ^= y; }