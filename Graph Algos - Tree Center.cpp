#include <bits/stdc++.h>
#include "Graph Structures - Edge (unweighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <bool Index> pair<deque<int>, vector<int>> find_centers(graph<0, edge, Index>& g) {
    vector<int> degree(g.adj.size()), height(g.adj.size());
    deque<int> q;
    for(int u = Index; u < g.adj.size(); u++) {
        if(degree[u] = g[u].size() <= 1) {
            height[u] = 1;
            q.push_back(u);
        }
    }
    for(int i = 0; i < q.size(); i++) {
        int u = q[i];
        for(int e : g[u]) {
            if(--degree[g(e).v] == 1) {
                height[g(e).v] = height[u] + 1;
                q.push_back(g(e).v);
            }
        }
    }
    while(height[q.front()] < height[q.back()]) {
        q.pop_front();
    }
    for(int u : q) {
        sort(g[u].begin(), g[u].end(), [&](int e1, int e2) { return height[g(e1).v] > height[g(e2).v]; });
    }
    return {move(q), move(height)};
}
