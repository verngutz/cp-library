#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
vector<complex<double>> pad(const vector<complex<double>>& a, int min_size) {
    while(min_size != (min_size & -min_size)) {
        min_size++;
    }
    vector<complex<double>> padded(min_size);
    copy(a.begin(), a.end(), padded.begin());
    return padded;
}
vector<complex<double>> fft(const vector<complex<double>>& a) {
    int n = a.size();
    if(n == 1) {
        return a;
    } else {
        vector<complex<double>> e(n / 2), o(n / 2);
        for(int i = 0; i < n; i++) {
            (i % 2 ? o : e)[i / 2] = a[i];
        }
        vector<complex<double>> fft_e = fft(e), fft_o = fft(o), ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = fft_e[i % (n / 2)] + exp(2i * (PI * i / n)) * fft_o[i % (n / 2)];
        }
        return ans;
    }
}
vector<complex<double>> conj(const vector<complex<double>>& a) {
    vector<complex<double>> ans(a.size());
    transform(a.begin(), a.end(), ans.begin(), [](complex<double> z) { return conj(z); });
    return ans;
}
vector<complex<double>> ifft(const vector<complex<double>>& a) {
    auto res = conj(fft(conj(a)));
    double n = a.size();
    transform(res.begin(), res.end(), res.begin(), [n](complex<double> z) { return z / n; });
    return res;
}
vector<complex<double>> multiply(const vector<complex<double>>& A, const vector<complex<double>>& B) {
    int product_size = A.size() + B.size() - 1;
    vector<complex<double>> a = fft(pad(A, product_size)), b = fft(pad(B, product_size)), c(a.size());
    for(int i = 0; i < a.size(); i++) {
        c[i] = a[i] * b[i];
    }
    return ifft(c);
}
