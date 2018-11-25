#include <bits/stdc++.h>
using namespace std;
template <typename Domain, typename Range>
Domain tsearch(Domain L, Domain R, const function<Range(Domain)>& f, bool concave_up = true) {
    while(R - L > 1) {
        Domain M = (L + R) / 2;
        ((concave_up ? f(M) < f(M + 1) : f(M) > f(M + 1)) ? R : L) = M;
    }
    return (concave_up ? f(L) < f(R) : f(L) > f(R)) ? L : R;
}
