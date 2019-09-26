#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
template <typename T> struct fedge {
    int u, v; T w, c, f;
    T resid() { return c - f; }
    fedge reverse() const { return {v, u, -w, 0, 0}; }
    friend ostream& operator<<(ostream& os, const fedge& e) {
        return os << "(" << e.u << ", " << e.v << ", " << e.w << ", " << e.c << ", " << e.f << ")";
    }
};
template <typename T, bool Index> using flow_graph = graph<0, fedge<T>, Index>;
template <typename T, bool Index> pair<T, T> min_cost_flow(flow_graph<T, Index>& g, int s, int t, T flow_limit = lim<T>::max()) {
    vector<int> vis(g.adj.size()), p(g.adj.size());
    vector<T> d(g.adj.size()), pot(g.adj.size());
    auto augment = [&]() {
        fill(vis.begin(), vis.end(), false);
        fill(d.begin(), d.end(), lim<T>::max());
        priority_queue<pair<T, int>> pq({}, {{d[s] = 0, s}});
        while(not pq.empty()) {
            int u = pq.top().second; pq.pop();
            if(not vis[u]) {
                vis[u] = true;
                for(int e : g[u]) {
                    if(not vis[g(e).v] and g(e).resid() > 0 and d[g(e).v] > d[g(e).u] + pot[g(e).u] + g(e).w - pot[g(e).v]) {
                        pq.push({-(d[g(e).v] = d[g(e).u] + pot[g(e).u] + g(e).w - pot[g(e).v]), g(p[g(e).v] = e).v});
                    }
                }
            }
        }
        return d[t] < lim<T>::max();
    };
    if(count_if(g.edges.begin(), g.edges.end(), [](const fedge<T>& e) { return e.c and e.w < 0; })) {
        fill(pot.begin(), pot.end(), lim<T>::max());
        pot[s] = 0;
        for(int i = 0; i < g.size() - 1; i++) {
            for(const fedge<T>& e : g.edges) {
                if(e.c and pot[e.u] < lim<T>::max()) {
                    pot[e.v] = min(pot[e.v], pot[e.u] + e.w);
                }
            }
        }
    }
    T flow = 0, cost = 0;
    while(flow < flow_limit and augment()) {
        T b = flow_limit - flow;
        for(int v = t; v != s; v = g(p[v]).u) {
            b = min(b, g(p[v]).resid());
        }
        for(int v = t; v != s; v = g(p[v]).u) {
            g(p[v]).f += b, g(p[v] ^ 1).f -= b;
            cost += b * g(p[v]).w;
        }
        flow += b;
        for(int u = Index; u < g.adj.size(); u++) {
            pot[u] += d[u];
        }
    }
    return {flow, cost};
}
