#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
vector<complex<double>> pad(const vector<complex<double>>& a, int min_size) {
    while(min_size != (min_size & -min_size)) {
        min_size++;
    }
    if(min_size == a.size()) {
        return a;
    } else {
        vector<complex<double>> padded(min_size);
        copy(a.begin(), a.end(), padded.begin());
        return padded;
    }
}
vector<complex<double>> fft(const vector<complex<double>>& a, bool inverse = false) {
    int n = a.size();
    if(n == 1) {
        return a;
    } else {
        vector<complex<double>> e(n / 2), o(n / 2);
        for(int j = 0; j < n; j++) {
            (j % 2 ? o : e)[j / 2] = a[j];
        }
        vector<complex<double>> fft_e = fft(e, inverse), fft_o = fft(o, inverse), ans(n);
        for(int j = 0; j < n; j++) {
            ans[j] = (fft_e[j % (n / 2)] + exp((inverse ? -2i : 2i) * (PI * j / n)) * fft_o[j % (n / 2)]) / (inverse ? 2.0 : 1.0);
        }
        return ans;
    }
}
vector<complex<double>> operator*(const vector<complex<double>>& A, const vector<complex<double>>& B) {
    vector<complex<double>> a = fft(pad(A, A.size())), b = fft(pad(B, B.size())), c(a.size());
    for(int j = 0; j < a.size(); j++) {
        c[j] = a[j] * b[j];
    }
    return fft(c, true);
}
vector<complex<double>> polynomial_multiply(const vector<complex<double>>& A, const vector<complex<double>>& B) {
    int product_size = A.size() + B.size() - 1;
    return pad(A, product_size) * pad(B, product_size);
}
vector<complex<double>> operator^(const vector<complex<double>>& X, long long y) {
    using f = function<vector<complex<double>>(const vector<complex<double>>&, long long)>;
    f poly_pow = [&](const vector<complex<double>>& x, long long y) {
        if(y == 0) {
            vector<complex<double>> id(x.size()); id[0] = 1;
            return id;
        } else {
            auto z = poly_pow(x, (y / 2));
            return y % 2 ? z * z * x : z * z;
        }
    };
    auto x = X;
    x.resize((X.size() - 1) * y + 1);
    return poly_pow(x, y);
}
