#include <bits/stdc++.h>
#include "Graph Structures - Edge (weighted).cpp"
#include "Graph Structures - Incidence List.cpp"
#include "Math - Modular Arithmetic.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
template <bool Directed, typename T, bool Index, typename TCount = mint>
pair<vector<T>, vector<TCount>> sssp_count(graph<Directed, wedge<T>, Index>& g, const vector<int>& s) {
    vector<int> vis(g.adj.size());
    vector<T> d(g.adj.size(), lim<T>::max());
    vector<TCount> c(g.adj.size(), 0);
    priority_queue<pair<T, int>> pq;
    for(int u : s) {
        pq.push({d[u] = 0, u});
        c[u] = 1;
    }
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(int e : g[u]) {
                if(d[g(e).v] > d[u] + g(e).w) {
                    pq.push({-(d[g(e).v] = d[u] + g(e).w), g(e).v});
                    c[g(e).v] = c[u];
                } else if(d[g(e).v] == d[u] + g(e).w) {
                    c[g(e).v] += c[u];
                }
            }
        }
    }
    return {move(d), move(c)};
}