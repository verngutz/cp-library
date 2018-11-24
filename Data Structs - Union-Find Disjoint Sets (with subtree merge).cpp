#include <bits/stdc++.h>
#include "Data Structs - Union-Find Disjoint Sets.cpp"
using namespace std;
class ufds_with_merge : public ufds {
    template <typename signature>
    using f = function<signature>;
private:
    vector<int> sz;
    f<void(int, int)> merge; // merge u into v
    f<bool(int, int)> merge_cmp; // merge(u, v) if merge_cmp(u, v) else merge(v, u)
public:
    ufds_with_merge(int n, const f<void(int, int)>& merge, const f<bool(int, int)>& merge_cmp)
    : ufds(n), merge(merge), merge_cmp(merge_cmp) {
        sz.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            sz[i] = 1;
        }
    }
    ufds_with_merge(int n, const f<void(int, int)>& merge)
    : ufds_with_merge(n, merge, [this](int u, int v) { return sz[u] < sz[v]; }) {}
    void onion(int u, int v) {
        int u_root = find(u), v_root = find(v);
        if(u_root != v_root) {
            if(not merge_cmp(u_root, v_root)) {
                swap(u_root, v_root);
                swap(u, v);
            }
            sz[v_root] += sz[u_root];
            merge(u_root, v_root);
        }
        ufds::onion(u, v);
    }
    int size(int u) {
        return sz[find(u)];
    }
};
