#include <bits/stdc++.h>
#include "Data Structs - Union-Find Disjoint Sets (with subtree merge).cpp"
using namespace std;
class ufds_members : public ufds_with_merge {
private:
    vector<vector<int>> members;
public:
    ufds_members(int n) : ufds_with_merge(n, [this](int u, int v) {
        auto middle = members[v].insert(members[v].end(), members[u].begin(), members[u].end());
        inplace_merge(members[v].begin(), middle, members[v].end());
        vector<int>().swap(members[u]);
    }) {
        members.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            members[i] = {i};
        }
    }
    bool exists(int u, int x) {
        return binary_search(members[find(u)].begin(), members[find(u)].end(), x);
    }
};
