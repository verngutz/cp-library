#include <bits/stdc++.h>
#include "Data Structs - Union-Find (with union-by-rank).cpp"
struct ufds_members : public ufds_with_rank {
    vector<vector<int>> members;
    ufds_members(int n) : ufds_with_rank(n, [this](int u, int v) {
        members[v].insert(members[v].end(), members[u].begin(), members[u].end());
        vector<int>().swap(members[u]);
    }), members(n + 1) {
        for(int i = 0; i <= n; i++) {
            members[i] = {i};
        }
    }
    vector<int>& get_members(int u) {
        return members[find(u)];
    }
};