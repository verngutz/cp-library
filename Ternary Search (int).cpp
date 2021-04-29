#include <bits/stdc++.h>
using namespace std;
template <typename TIn, typename TOut, typename Obj, typename Cmp = decltype(less<TOut>())>
TIn tsearch(TIn L, TIn R, Obj&& obj, Cmp&& cmp = less<TOut>()) {
    static_assert(is_convertible<Obj, function<TOut(TIn)>>::value);
    static_assert(is_convertible<Cmp, function<bool(TOut, TOut)>>::value);
    while(R - L > 1) {
        TIn M = (L + R) / 2;
        (cmp(obj(M), obj(M + 1)) ? R : L) = M;
    }
    return cmp(obj(L), obj(R)) ? L : R;
}
