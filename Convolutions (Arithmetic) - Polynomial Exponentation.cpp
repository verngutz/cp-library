#include <bits/stdc++.h>
#include "FFTs - Convolution (Discrete Fourier Transform).cpp"
using namespace std;
template <typename T> vector<T> operator^=(vector<T>& x, long long y) {
    fft(pad(x, (x.size() - 1) * y + 1));
    transform(x.begin(), x.end(), x.begin(), [y](T& xi) { return fpow(xi, y); });
    return fft(x, true);
}
template <typename T> vector<T> operator^(vector<T> x, long long y) { return x ^= y; }
