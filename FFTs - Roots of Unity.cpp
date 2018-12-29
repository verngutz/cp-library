#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
complex<double> w(int len, bool inverse) {
    return exp((inverse ? -2i : 2i) * (PI / len));
}
