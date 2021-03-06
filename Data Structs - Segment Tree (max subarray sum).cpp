#include <bits/stdc++.h>
#include "Data Structs - Segment Tree (compact).cpp"
using namespace std;
using ll = long long;
struct mss_node { ll max_sub, all, prefix, suffix; };
template <ll INF> struct mss_segtree : public segtree<mss_node> {
    mss_segtree(int size) : segtree<mss_node>(size, {{-INF, 0, -INF, -INF}, [](const mss_node& L, const mss_node& R) {
        return mss_node{
            max({L.max_sub, R.max_sub, L.suffix + R.prefix}),
            L.all + R.all,
            max(L.prefix, L.all + R.prefix),
            max(R.suffix, R.all + L.suffix)
        };
    }}) {}
    void update(int i, ll x) { segtree<mss_node>::update(i, {x, x, x, x}); }
};
