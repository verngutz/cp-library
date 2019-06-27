#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
#include "FFTs - Roots of Unity.cpp"
#include "FFTs - Primitive Roots (for Number-Theoretic Transform).cpp"
using namespace std;
constexpr int lg(int x) { return 31 - __builtin_clz(x); }
template <typename T> vector<T>& pad(vector<T>& a, int min_size) {
    a.resize(2 << lg(min_size - 1));
    return a;
}
int bit_reverse(int i, int n) {
    int ans = 0;
    for(int j = 0; j < lg(n); j++) {
        ans |= i & (1 << j) ? 1 << (lg(n) - 1 - j) : 0;
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
        T W = w(len, inverse);
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
        transform(a.begin(), a.end(), a.begin(), [n](T& ai) { return ai / n; });
    }
    return a;
}
template <typename T> vector<T>& operator*=(vector<T>& a, vector<T>& b) {
    fft(pad(a, a.size())); if(addressof(a) != addressof(b)) fft(pad(b, b.size()));
    transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<T>());
    fft(a, true); if(addressof(a) != addressof(b)) fft(b, true);
    return a;
}
template <typename T> vector<T> operator*(vector<T>& a, vector<T>& b) {
    vector<T> acopy = a;
    return acopy *= b;
}
template <typename T> vector<T> multiply(vector<T>& a, vector<T>& b) {
    int product_size = a.size() + b.size() - 1;
    return pad(a, product_size) * pad(b, product_size);
}
template <typename T> vector<T> operator^=(vector<T>& x, long long y) {
    fft(pad(x, (x.size() - 1) * y + 1));
    transform(x.begin(), x.end(), x.begin(), [y](T& xi) { return fpow(xi, y); });
    return fft(x, true);
}
template <typename T> vector<T> operator^(vector<T>& x, long long y) {
    vector<T> xcopy = x;
    return xcopy ^= y;
}
