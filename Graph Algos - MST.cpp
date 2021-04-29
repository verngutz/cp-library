#include <bits/stdc++.h>
#include "Graph Structures - Edge (weighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
template <bool Directed, typename T, bool Index>
pair<T, vector<int>> mst(graph<Directed, wedge<T>, Index>& g, int s = Index) {
    vector<int> vis(g.adj.size()), p(g.adj.size(), -1);
    vector<T> d(g.adj.size(), lim<T>::max());
    priority_queue<pair<T, int>> pq({}, {{d[s] = 0, s}});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(int e : g[u]) {
                if(not vis[g(e).v] and d[g(e).v] > g(e).w) {
                    pq.push({-(d[g(e).v] = g(e).w), g(p[g(e).v] = e).v});
                }
            }
        }
    }
    return {accumulate(d.begin() + Index, d.end(), T(0)), move(p)};
}
