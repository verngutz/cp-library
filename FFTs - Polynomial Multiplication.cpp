#include <bits/stdc++.h>
#include "FFTs - Convolution (Discrete Fourier Transform).cpp"
using namespace std;
template <typename T> vector<T> multiply(vector<T>& a, vector<T>& b) {
    int product_size = a.size() + b.size() - 1;
    return pad(a, product_size) * pad(b, product_size);
}
