#include <bits/stdc++.h>
#include "Binary Search.cpp"
using namespace std;

int main() {
    int a[] = {1, 1, 1, 3, 3, 3, 3, 7, 7, 7, 10};

    assert(gt(a, a + 11, 5) == 7);
    assert(gt(a, a + 11, 7) == 10);
    assert(gt(a, a + 11, 10) == 11);

    assert(lt(a, a + 11, 5) == 6);
    assert(lt(a, a + 11, 3) == 2);
    assert(lt(a, a + 11, 1) == -1);

    assert(ge(a, a + 11, 5) == 7);
    assert(ge(a, a + 11, 7) == 7);
    assert(ge(a, a + 11, 10) == 10);
    assert(ge(a, a + 11, 11) == 11);

    assert(le(a, a + 11, 5) == 6);
    assert(le(a, a + 11, 3) == 6);
    assert(le(a, a + 11, 1) == 2);
    assert(le(a, a + 11, 0) == -1);

    set<int> s(a, a + 11);
    assert(*gt(s, 5) == 7);
    assert(*gt(s, 7) == 10);
    assert(gt(s, 10) == s.end());

    assert(*lt(s, 5) == 3);
    assert(*lt(s, 3) == 1);
    assert(lt(s, 1) == s.end());

    assert(*ge(s, 5) == 7);
    assert(*ge(s, 7) == 7);
    assert(*--ge(s, 7) == 3);
    assert(*ge(s, 10) == 10);
    assert(ge(s, 11) == s.end());

    assert(*le(s, 5) == 3);
    assert(*le(s, 3) == 3);
    assert(*++le(s, 3) == 7);
    assert(*le(s, 1) == 1);
    assert(le(s, 0) == s.end());

    map<int, int> m;
    for(int i = 0; i < 11; i++) {
        m[a[i]] = i;
    }
    assert(gt(m, 5)->first == 7);
    assert(gt(m, 7)->first == 10);
    assert(gt(m, 10) == m.end());

    assert(lt(m, 5)->first == 3);
    assert(lt(m, 3)->first == 1);
    assert(lt(m, 1) == m.end());

    assert(ge(m, 5)->first == 7);
    assert(ge(m, 7)->first == 7);
    assert((--ge(m, 7))->first == 3);
    assert(ge(m, 10)->first == 10);
    assert(ge(m, 11) == m.end());

    assert(le(m, 5)->first == 3);
    assert(le(m, 3)->first == 3);
    assert((++le(m, 3))->first == 7);
    assert(le(m, 1)->first == 1);
    assert(le(m, 0) == m.end());
}
