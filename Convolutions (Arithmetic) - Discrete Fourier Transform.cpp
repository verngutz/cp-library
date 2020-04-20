#include <bits/stdc++.h>
#include "FFTs - Roots of Unity (Complex).cpp"
#include "FFTs - Roots of Unity (Number-Theoretic).cpp"
using namespace std;
template <typename T> vector<T>& pad(vector<T>& a, int min_size) {
    a.resize(2 << __lg(min_size - 1));
    return a;
}
int bit_reverse(int i, int n) {
    int ans = 0;
    for(int j = 0; j < __lg(n); j++) {
        ans |= i & (1 << j) ? 1 << (__lg(n) - 1 - j) : 0;
    }
    return ans;
}
template <typename T> vector<T>& fft(vector<T>& a, bool inverse = false) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(i < bit_reverse(i, n)) {
            swap(a[i], a[bit_reverse(i, n)]);
        }
    }
    for(int len = 2; len <= n; len <<= 1) {
        T W = w<T>(len, inverse);
        for(int i = 0; i < n; i += len) {
            T root = 1;
            for(int j = i; j < i + (len >> 1); j++) {
                T u = a[j], t = root * a[j + (len >> 1)];
                a[j] = u + t;
                a[j + (len >> 1)] = u - t;
                root *= W;
            }
        }
    }
    if(inverse) {
        transform(a.begin(), a.end(), a.begin(), [n](T& ai) { return ai / T(n); });
    }
    return a;
}
template <typename T> vector<T>& operator*=(vector<T>& a, vector<T>& b) {
    fft(pad(a, a.size()));
    if(addressof(a) != addressof(b)) fft(pad(b, b.size()));
    assert(a.size() == b.size());
    transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<T>());
    if(addressof(a) != addressof(b)) fft(b, true);
    return fft(a, true);
}
template <typename T> vector<T> operator*(vector<T> a, vector<T>& b) { return a *= b; }
