#include <bits/stdc++.h>
#include "Data Structs - Monoid.cpp"
using namespace std;
template <typename T> struct segtree {
    using Type = T;
    using DeltaType = T;
    const int size;
    vector<T> tree;
    const monoid<T> m;
    segtree(int size, const monoid<T>& m) : size(size), tree(2 * (size + 1), m.identity), m(m) {}
    void update(int i, T x) {
        for(tree[i += size] = x; i >>= 1; )
            tree[i] = m.combine(tree[i << 1], tree[(i << 1) | 1]);
    }
    T query(int a, int b, bool inclusive) {
        assert(a <= b);
        T ans_l = m.identity, ans_r = m.identity;
        for(a += size, b += size + inclusive; a < b; a >>= 1, b >>= 1) {
            if(a & 1) ans_l = m.combine(ans_l, tree[a++]);
            if(b & 1) ans_r = m.combine(tree[--b], ans_r);
        }
        return m.combine(ans_l, ans_r);
    }
    T query(int i) { return query(i, i, true); }
    friend ostream& operator<<(ostream& os, segtree& t) {
        os << "[";
        for(int i = 0; i <= t.size; i++) {
            if(i != 0) os << ", ";
            os << t.query(i);
        }
        return os << "]";
    }
};
