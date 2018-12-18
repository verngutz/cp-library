#include <bits/stdc++.h>
#include "Graph - Adjacency List (unweighted).cpp"
using namespace std;
using ll = long long;
pair<deque<int>, vector<int>> find_centers(graph<0>& g) {
    vector<int> degree(g.n + 1), height(g.n + 1);
    deque<int> q;
    for(int u = 1; u <= g.n; u++) {
        degree[u] = g.adj[u].size();
        if(degree[u] <= 1) {
            height[u] = 1;
            q.push_back(u);
        }
    }
    for(int i = 0; i < q.size(); i++) {
        int u = q[i];
        for(auto [u, v, i] : g.adj[u]) {
            if(--degree[v] == 1) {
                height[v] = height[u] + 1;
                q.push_back(v);
            }
        }
    }
    while(height[q.front()] < height[q.back()]) {
        q.pop_front();
    }
    for(int u : q) {
        sort(g.adj[u].begin(), g.adj[u].end(), [&](edge& e1, edge& e2) { return height[e1.v] > height[e2.v]; });
    }
    return {q, height};
}
int diameter(graph<0>& g) {
    auto [centers, height] = find_centers(g);
    if(g.n == 1) {
        return 0;
    } else if(g.n == 2) {
        return 1;
    } else if(centers.size() == 1) {
        return height[g.adj[centers[0]][0].v] + height[g.adj[centers[0]][1].v];
    } else {
        return height[g.adj[centers[0]][1].v] + height[g.adj[centers[1]][1].v] + 1;
    }
}
