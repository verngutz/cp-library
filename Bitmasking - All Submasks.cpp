#include <bits/stdc++.h>
using namespace std;
template <typename F> void for_each_subset(int mask, F&& f) {
    static_assert(is_convertible<decltype(f), function<void(int)>>::value);
    for(int x = mask; x > 0; x = (x - 1) & mask) {
        f(x);
    }
}
