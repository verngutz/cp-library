#include <bits/stdc++.h>
using namespace std;
template <typename signature> using f = const function<signature>&;
template <typename TIn, typename TOut> TIn tsearch(TIn L, TIn R, f<TOut(TIn)> obj, f<bool(TOut, TOut)> cmp = less<TOut>()) {
    for(int i = 0; i < 1000; i++) {
        TIn M1 = (2 * L + R) / 3;
        TIn M2 = (L + 2 * R) / 3;
        cmp(obj(M1), obj(M2)) ? R = M2 : L = M1;
    }
    return cmp(obj(L), obj(R)) ? L : R;
}
