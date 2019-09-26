#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
template <typename T = complex<double>> complex<double> w(int len, bool inverse) {
    return polar<double>(1, (inverse ? -2 : 2) * (PI / len));
}
