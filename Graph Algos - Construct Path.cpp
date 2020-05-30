#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <bool Directed, typename TEdge, bool Index>
vector<int> construct_path(graph<Directed, TEdge, Index>& g, const vector<int>& parent, int t) {
    vector<int> ans = {t};
    while(parent[ans.back()] != -1) {
        ans.push_back(g(parent[ans.back()]).u);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
