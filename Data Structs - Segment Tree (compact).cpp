#include <bits/stdc++.h>
using namespace std;
template <typename T> struct segtree {
    using Type = T;
    using DeltaType = T;
    const int size;
    vector<T> tree;
    const T zero;
    const function<T(T, T)> combine;
    segtree(int size, T zero, const function<T(T, T)>& combine)
    : size(size), tree(2 * (size + 1), zero), zero(zero), combine(combine) {}
    void update(int i, T x) {
        for(tree[i += size] = x; i >>= 1; )
            tree[i] = combine(tree[i << 1], tree[(i << 1) | 1]);
    }
    T query(int a, int b, bool inclusive) {
        assert(a <= b);
        T ans_l = zero, ans_r = zero;
        for(a += size, b += size + inclusive; a < b; a >>= 1, b >>= 1) {
            if(a & 1) ans_l = combine(ans_l, tree[a++]);
            if(b & 1) ans_r = combine(tree[--b], ans_r);
        }
        return combine(ans_l, ans_r);
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
