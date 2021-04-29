#include <bits/stdc++.h>
#include "Graph Structures - Edge (weighted).cpp"
#include "Graph Structures - Incidence List.cpp"
using namespace std;
using ll = long long;
template <bool Directed, typename T, bool Index>
tuple<vector<T>, vector<int>, vector<bool>> sssp(graph<Directed, wedge<T>, Index>& g, int s) {
    vector<T> d(g.adj.size(), ll(g.size()) * max_element(g.edges.begin(), g.edges.end(), [](wedge<T>& e1, wedge<T>& e2) {
        return e1->w < e2->w;
    })->w);
    vector<int> p(g.adj.size()), neg_cycle(g.adj.size());
    d[s] = 0;
    for(int i = 0; i < g.size() - 1; i++) {
        for(const wedge<T>& e : g.edges) {
            if(d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                p[e.v] = e;
            }
        }
    }
    for(int i = 0; i < g.size() - 1; i++) {
        for(const wedge<T>& e : g.edges) {
            if(d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                neg_cycle[e.v] = true;
            }
        }
    }
    return {move(d), move(p), move(neg_cycle)};
}
