#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
template <typename T, typename D> struct segtree {
    using Type = T;
    using DeltaType = D;
    template <typename signature> using f = const function<signature>;
    const T zero; f<T(T, T)> combine; // combine two elements of list
    const D dzero; f<D(D, D)> dcombine; // combine two update operations
    f<T(T, D, int, int)> lcombine; // lazy query with segtree value T, lazy flag D, start index, end index
    const int size;
    vector<T> a, st;
    vector<D> delta;
    vector<bool> is_lazy;
    int L(int p) { return 2 * p; }
    int R(int p) { return 2 * p + 1; }
    int m(int s, int e) { return (s + e) / 2; }
    void pull(int p, int s, int e) {
        st[p] = combine(get_val(L(p), s, m(s, e)), get_val(R(p), m(s, e) + 1, e));
    }
    void lazy(int p, D v) {
        delta[p] = dcombine(delta[p], v), is_lazy[p] = true;
    }
    void unlazy(int p, int s, int e) {
        if(is_lazy[p]) {
            if(s != e) lazy(L(p), delta[p]), lazy(R(p), delta[p]);
            delta[p] = dzero, is_lazy[p] = false;
            pull(p, s, e);
        }
    }
    T get_val(int p, int s, int e) {
        return is_lazy[p] ? lcombine(st[p], delta[p], s, e) : st[p];
    }
    T build(int p, int s, int e) {
        delta[p] = dzero, is_lazy[p] = false;
        if(s == e) {
            return st[p] = a[s];
        } else {
            return st[p] = combine(build(L(p), s, m(s, e)), build(R(p), m(s, e) + 1, e));
        }
    }
    segtree(T zero, f<T(T, T)>& combine, D dzero, f<D(D, D)>& dcombine, f<T(T, D, int, int)>& lcombine, const vector<T>& a)
    : zero(zero), combine(combine), dzero(dzero), dcombine(dcombine), lcombine(lcombine), size(a.size() - 1), a(a),
    st(4 * (size + 1)), delta(4 * (size + 1)), is_lazy(4 * (size + 1)) {
        build(1, 1, size);
    }
    segtree(T zero, f<T(T, T)>& combine, D dzero, f<D(D, D)>& dcombine, f<T(T, D, int, int)>& lcombine, int size)
    : segtree(zero, combine, dzero, dcombine, lcombine, vector<T>(size + 1, zero)) {}
    T query(int l, int r, int p, int s, int e) {
        if(l <= s and e <= r) {
            return get_val(p, s, e);
        } else if(r < s or e < l) {
            return zero;
        } else {
            unlazy(p, s, e);
            return combine(query(l, r, L(p), s, m(s, e)), query(l, r, R(p), m(s, e) + 1, e));
        }
    }
    T query(int l, int r) { return query(l, r, 1, 1, size); }
    T query(int i) { return query(i, i); }
    void update(int l, int r, D v, int p, int s, int e) {
        if(l <= s and e <= r) {
            lazy(p, v);
        } else if(not (r < s or e < l)) {
            unlazy(p, s, e);
            update(l, r, v, L(p), s, m(s, e)), update(l, r, v, R(p), m(s, e) + 1, e);
            pull(p, s, e);
        }
    }
    void update(int l, int r, D v) { update(l, r, v, 1, 1, size); }
    void update(int i, D v) { update(i, i, v); }
};
template<typename T, typename D> ostream& operator<<(ostream& os, segtree<T, D>& t) {
    os << "[";
    bool comma = false;
    for(int i = 1; i <= t.size; i++) {
        if(comma) os << ", "; else comma = true;
        os << t.query(i, i);
    }
    os << "]";
    return os;
}
