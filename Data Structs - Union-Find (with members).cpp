#include <bits/stdc++.h>
#include "Data Structs - Union-Find (with union-by-rank).cpp"
using namespace std;
struct ufds_members : public ufds_with_rank {
    vector<vector<int>> members;
    ufds_members(int n) : ufds_with_rank(n, [this](int u, int v) {
        auto middle = members[v].insert(members[v].end(), members[u].begin(), members[u].end());
        inplace_merge(members[v].begin(), middle, members[v].end());
        vector<int>().swap(members[u]);
    }), members(n + 1) {
        for(int i = 0; i <= n; i++) {
            members[i] = {i};
        }
    }
};