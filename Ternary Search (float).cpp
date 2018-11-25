#include <bits/stdc++.h>
using namespace std;
template <typename Range>
double tsearch(double L, double R, const function<Range(double)>& f, bool concave_up = true) {
    for(int i = 0; i < 1000; i++) {
        double M1 = (2 * L + R) / 3;
        double M2 = (L + 2 * R) / 3;
        (concave_up ? f(M1) < f(M2) : f(M1) > f(M2)) ? R = M2 : L = M1;
    }
    return (concave_up ? f(L) < f(R) : f(L) > f(R)) ? L : R;
}
