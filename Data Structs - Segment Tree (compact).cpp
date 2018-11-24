#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct segtree {
    using Type = T;
    using DeltaType = T;
    const T zero;
    const function<T(T, T)> combine;
    const int size;
    vector<T> tree;
    segtree(T zero, const function<T(T, T)>& combine, int size)
    : zero(zero), combine(combine), size(size + 1), tree(2 * (size + 1), zero) {}
    void update(int i, T x) { // arr[i] = x
        for(tree[i += size] = x; i >>= 1; )
            tree[i] = combine(tree[i << 1], tree[(i << 1) | 1]);
    }
    T query(int a, int b) { // sum[a, b]
        T ans_l = zero, ans_r = zero;
        for(a += size, b += size + 1; a < b; a >>= 1, b >>= 1) {
            if(a & 1) ans_l = combine(ans_l, tree[a++]);
            if(b & 1) ans_r = combine(tree[--b], ans_r);
        }
        return combine(ans_l, ans_r);
    }
};
