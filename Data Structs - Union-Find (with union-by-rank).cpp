#include <bits/stdc++.h>
#include "Data Structs - Union-Find.cpp"
using namespace std;
struct ufds_with_rank : public ufds {
    template <typename signature> using f = const function<signature>;
    vector<int> rank;
    f<void(int, int)> merge; // merge u into v
    f<bool(int, int)> merge_cmp; // merge(u, v) if merge_cmp(u, v) else merge(v, u)
    ufds_with_rank(int n, f<void(int, int)> merge, f<bool(int, int)>& merge_cmp)
    : ufds(n), rank(n + 1, 1), merge(merge), merge_cmp(merge_cmp) {}
    ufds_with_rank(int n, f<void(int, int)> merge)
    : ufds_with_rank(n, merge, [this](int u, int v) { return rank[u] < rank[v]; }) {}
    void onion(int u, int v) {
        int u_root = find(u), v_root = find(v);
        if(u_root != v_root) {
            if(not merge_cmp(u, v)) swap(u_root, v_root);
            rank[v_root] += rank[u_root];
            merge(u_root, v_root);
            ufds::onion(u_root, v_root);
        }
    }
};
