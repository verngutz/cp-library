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
        for(int j = 0; j < n; j++) {
            (j % 2 ? o : e)[j / 2] = a[j];
        }
        vector<complex<double>> fft_e = fft(e), fft_o = fft(o), ans(n);
        for(int j = 0; j < n; j++) {
            ans[j] = fft_e[j % (n / 2)] + exp(2i * (PI * j / n)) * fft_o[j % (n / 2)];
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
    for(int j = 0; j < a.size(); j++) {
        c[j] = a[j] * b[j];
    }
    return ifft(c);
}
