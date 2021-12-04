#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<T>& operator+=(vector<T>& p, const vector<T>& q) {
    p.resize(max(p.size(), q.size()));
    transform(p.begin(), p.begin() + min(p.size(), q.size()), q.begin(), p.begin(), plus<T>());
    return p;
}
template <typename T> vector<T> operator+(vector<T> p, const vector<T>& q) { return move(p += q); }
template <typename T> vector<T>& operator-=(vector<T>& p, const vector<T>& q) {
    transform(p.begin(), p.begin() + min(p.size(), q.size()), q.begin(), p.begin(), minus<T>());
    return p;
}
template <typename T> vector<T> operator-(vector<T> p, const vector<T>& q) { return move(p -= q); }
template <typename T> vector<T>& operator*=(vector<T>& p, const T& scalar) {
    transform(p.begin(), p.end(), p.begin(), [&](const T& component) { return move(component * scalar); });
    return p;
}
template <typename T> vector<T> operator*(vector<T> p, const T& scalar) { return move(p *= scalar); }
template <typename T> vector<T> operator*(const T& scalar, vector<T> p) { return move(p *= scalar); }
template <typename T> vector<T>& operator/=(vector<T>& p, const T& scalar) {
    transform(p.begin(), p.end(), p.begin(), [&](const T& component) { return move(component / scalar); });
    return p;
}
template <typename T> vector<T> operator/(vector<T> p, const T& scalar) { return move(p /= scalar); }
template <typename T> vector<T> operator*(const vector<T>& a, const vector<T>& b) {
    vector<T> ans(a.size() + b.size() - 1);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            ans[i + j] += a[i] * b[j];
        }
    }
    return ans;
}
template <typename T> vector<T>& operator*=(vector<T>& a, const vector<T>& b) { return a = a * b; }
