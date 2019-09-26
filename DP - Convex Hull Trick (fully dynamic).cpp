#include <bits/stdc++.h>
#include "Data Structs - Segment Tree (compact).cpp"
using namespace std;
using ll = long long;
// maintain an upper/lower hull L of lines y = mx + b
// query for y(x) such that y(x) is minimum/maximum over all lines y in L
// fully dynamic variant: lines can be inserted in any order of m
// minimization by default, call constructor with greater<ll>() for maximization
int LSB(int x) { return x & -x; }
int log2(int x) { return 31 - __builtin_clz(x); }
int st_size(int size) {
    return (size == LSB(size) ? size : 1 << (log2(size) + 1)) << 1;
}
struct cht {
    struct line {
        ll m, b;
        ll eval(ll x) const { return m * x + b; }
    };
    const int size;
    vector<line> st;
    const function<bool(ll, ll)> cmp;
    cht(int size, const function<bool(ll, ll)>& cmp = less<ll>())
    : size(size), cmp(cmp) {}
    int L(int p) { return (p << 1) + 1; }
    int R(int p) { return (p << 1) + 2; }
    int M(int s, int e) { return (s + e) >> 1; }
    void add(const line& l, int p, int s, int e) {
        if(cmp(l.eval(M(s, e)), st[p].eval(M(s, e)))) st[p] = l;
        if(s != e) {
            if((st[p].eval(s) < l.eval(s)) != (st[p].eval(M(s, e)) < l.eval(M(s, e)))) {
                add(l, L(p), s, M(s, e));
            } else {
                add(l, R(p), M(s, e) + 1, e);
            }
        }
    }
    void add(ll m, ll b) {
        if(st.empty()) {
            st.resize(st_size(size), {m, b});
        } else {
            add({m, b}, 0, 0, size - 1);
        }
    }
    ll opt(ll x, ll y) { return cmp(x, y) ? x : y; }
    ll opt(ll x, int p, int s, int e) {
        ll ans = st[p].eval(x);
        if(s != e) {
            ans = opt(ans, x <= M(s, e) ? opt(x, L(p), s, M(s, e)) : opt(x, R(p), M(s, e) + 1, e));
        }
        return ans;
    }
    ll opt(ll x) { return opt(x, 0, 0, size - 1); }
};
