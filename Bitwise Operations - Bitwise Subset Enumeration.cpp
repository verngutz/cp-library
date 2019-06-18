#include <bits/stdc++.h>
using namespace std;
void for_each_on_bit(int mask, const function<void(int)>& f) {
    for(int x = mask; x > 0; x -= x & -x) {
        f(__builtin_ffs(x & -x) - 1);
    }
}
void for_each_on_bit_pair(int mask, const function<void(int, int)>& f) {
    for(int x = mask; x > 0; x -= x & -x) {
        for(int y = x - (x & -x); y > 0; y -= y & -y) {
            f(__builtin_ffs(x & -x) - 1, __builtin_ffs(y & -y) - 1);
        }
    }
}
void for_each_on_bit_triple(int mask, const function<void(int, int, int)>& f) {
    for(int x = mask; x > 0; x -= x & -x) {
        for(int y = x - (x & -x); y > 0; y -= y & -y) {
            for(int z = y - (y & -y); z > 0; z -= z & -z) {
                f(__builtin_ffs(x & -x) - 1, __builtin_ffs(y & -y) - 1, __builtin_ffs(z & -z) - 1);
            }
        }
    }
}
void for_each_subset(int mask, const function<void(int)>& f) {
    for(int x = mask; x > 0; x = (x - 1) & mask) {
        f(x);
    }
}
