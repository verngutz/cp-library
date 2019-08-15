#include <bits/stdc++.h>
using namespace std;
template <typename TIn, typename TOut, typename Obj, typename Cmp = decltype(less<TOut>())>
TIn tsearch(TIn L, TIn R, Obj&& obj, Cmp&& cmp = less<TOut>()) {
    static_assert(is_convertible<Obj, function<TOut(TIn)>>::value, "obj must be TOut(TIn)");
    static_assert(is_convertible<Cmp, function<bool(TOut, TOut)>>::value, "cmp must be bool(TOut, TOut)");
    for(int i = 0; i < 1000; i++) {
        TIn M1 = (2 * L + R) / 3;
        TIn M2 = (L + 2 * R) / 3;
        cmp(obj(M1), obj(M2)) ? R = M2 : L = M1;
    }
    return cmp(obj(L), obj(R)) ? L : R;
}
