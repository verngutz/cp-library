#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
#include "FFTs - Roots of Unity.cpp"
#include "FFTs - Primitive Roots (NTT).cpp"
using namespace std;
template <typename T> vector<T>& pad(vector<T>& a, int min_size) {
    int size = 1;
    while(size < min_size) {
        size <<= 1;
    }
    a.resize(size);
    return a;
}
int bit_reverse(int i, int n) {
    int lgn = 31 - __builtin_clz(n);
    int ans = 0;
    for(int j = 0; j < lgn; j++) {
        ans |= i & (1 << j) ? 1 << (lgn - 1 - j) : 0;
    }
    return ans;
}
template <typename T> vector<T>& fft(vector<T>& a, bool inverse = false) {
    for(int i = 0; i < a.size(); i++) {
        if(i < bit_reverse(i, a.size())) {
            swap(a[i], a[bit_reverse(i, a.size())]);
        }
    }
    for(int len = 2; len <= a.size(); len <<= 1) {
        T W = w(len, inverse);
        for(int i = 0; i < a.size(); i += len) {
            T root = 1;
            for(int j = i; j < i + (len >> 1); j++) {
                auto u = a[j], t = root * a[j + (len >> 1)];
                a[j] = u + t;
                a[j + (len >> 1)] = u - t;
                root *= W;
            }
        }
    }
    if(inverse) {
        for(auto& x : a) {
            x /= a.size();
        }
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
    auto c = a;
    return c *= b;
}
template <typename T> vector<T> multiply(vector<T>& a, vector<T>& b) {
    int product_size = a.size() + b.size() - 1;
    return pad(a, product_size) * pad(b, product_size);
}
template <typename T> vector<T> operator^(vector<T>& x, long long y) {
    fft(pad(x, (x.size() - 1) * y + 1));
    vector<T> ans(x.size());
    for(int i = 0; i < ans.size(); i++) {
        ans[i] = fpow(x[i], y);
    }
    return fft(ans, true);
}
