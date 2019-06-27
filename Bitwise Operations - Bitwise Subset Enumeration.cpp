#include <bits/stdc++.h>
using namespace std;
void for_each_subset(int mask, const function<void(int)>& f) {
    for(int x = mask; x > 0; x = (x - 1) & mask) {
        f(x);
    }
}
