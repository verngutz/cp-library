#include <bits/stdc++.h>
#include "Misc - Lg.cpp"
using namespace std;
template <typename T, typename D> struct segtree {
    static constexpr int st_size(int size) { return (4 << lg(size - 1)) - 1; }
    using Type = T;
    using DeltaType = D;
    const int size;
    template <typename signature> using f = const function<signature>;
    const T zero; f<T(T, T)> combine; // combine two elements of list
    const D dzero; f<D(D, D)> dcombine; // combine two update operations
    f<T(T, D, int, int)> lcombine; // lazy query with segtree value T, lazy flag D, start index, end index
    vector<T> st;
    vector<D> delta;
    vector<bool> is_lazy;
    int L(int p) { return (p << 1) + 1; }
    int R(int p) { return (p << 1) + 2; }
    int m(int s, int e) { return (s + e) >> 1; }
    void pull(int p, int s, int e) {
        st[p] = combine(get_val(L(p), s, m(s, e)), get_val(R(p), m(s, e), e));
    }
    void lazy(int p, D v) {
        delta[p] = dcombine(delta[p], v), is_lazy[p] = true;
    }
    void unlazy(int p, int s, int e) {
        if(is_lazy[p]) {
            if(e - s > 1) lazy(L(p), delta[p]), lazy(R(p), delta[p]);
            delta[p] = dzero, is_lazy[p] = false;
            pull(p, s, e);
        }
    }
    T get_val(int p, int s, int e) {
        return is_lazy[p] ? lcombine(st[p], delta[p], s, e) : st[p];
    }
    T build(const vector<T>& a, int p, int s, int e) {
        delta[p] = dzero, is_lazy[p] = false;
        if(e - s > 1) {
            return st[p] = combine(build(a, L(p), s, m(s, e)), build(a, R(p), m(s, e), e));
        } else {
            return st[p] = a[s];
        }
    }
    segtree(const vector<T>& a, T zero, f<T(T, T)>& combine, D dzero, f<D(D, D)>& dcombine, f<T(T, D, int, int)>& lcombine)
    : size(a.size()), zero(zero), combine(combine), dzero(dzero), dcombine(dcombine), lcombine(lcombine),
    st(st_size(size)), delta(st_size(size)), is_lazy(st_size(size)) {
        build(a, 0, 0, size);
    }
    segtree(int size, T zero, f<T(T, T)>& combine, D dzero, f<D(D, D)>& dcombine, f<T(T, D, int, int)>& lcombine)
    : segtree(vector<T>(size + 1, zero), zero, combine, dzero, dcombine, lcombine) {}
    T query(int l, int r, int p, int s, int e) {
        if(l <= s and e <= r) {
            return get_val(p, s, e);
        } else if(r <= s or e <= l) {
            return zero;
        } else {
            unlazy(p, s, e);
            return combine(query(l, r, L(p), s, m(s, e)), query(l, r, R(p), m(s, e), e));
        }
    }
    T query(int l, int r, bool inclusive) {
        assert(l <= r);
        return query(l, r + inclusive, 0, 0, size);
    }
    T query(int i) { return query(i, i, true); }
    void update(int l, int r, D v, int p, int s, int e) {
        if(l <= s and e <= r) {
            lazy(p, v);
        } else if(not (r <= s or e <= l)) {
            unlazy(p, s, e);
            update(l, r, v, L(p), s, m(s, e)), update(l, r, v, R(p), m(s, e), e);
            pull(p, s, e);
        }
    }
    void update(int l, int r, D v, bool inclusive) {
        assert(l <= r);
        update(l, r + inclusive, v, 0, 0, size);
    }
    void update(int i, D v) { update(i, i, v, true); }
    friend ostream& operator<<(ostream& os, segtree& t) {
        os << "[";
        for(int i = 0; i <= t.size; i++) {
            if(i != 0) os << ", ";
            os << t.query(i);
        }
        return os << "]";
    }
};
