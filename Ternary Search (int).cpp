#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>&;
template <typename TIn, typename TOut> TIn tsearch(TIn L, TIn R, f<TOut(TIn)> obj, f<bool(TOut, TOut)> cmp = less<TOut>()) {
    while(R - L > 1) {
        TIn M = (L + R) / 2;
        (cmp(obj(M), obj(M + 1)) ? R : L) = M;
    }
    return cmp(obj(L), obj(R)) ? L : R;
}
