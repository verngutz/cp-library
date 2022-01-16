#include <bits/stdc++.h>
using namespace std;
template <bool Index> struct graph {
    int L, R;
    vector<vector<int>> adj;
    graph(int L, int R) : L(L), R(R), adj(L + Index) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
};
template <bool Index> vector<int> max_matching(graph<Index>& g) {
    vector<bool> matched(g.L + Index);
    vector<int> partner(g.R + Index, -1), d(g.L + Index), adj_ptr(g.L + Index);
    auto make_level_graph = [&]() {
        fill(d.begin(), d.end(), -1);
        queue<int> q;
        for(int u = Index; u < matched.size(); u++) {
            if(not matched[u]) {
                d[u] = 0;
                q.push(u);
            }
        }
        bool has_unmatched = false;
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g.adj[u]) {
                if(partner[v] == -1) {
                    has_unmatched = true;
                } else if(d[partner[v]] == -1) {
                    d[partner[v]] = d[u] + 1;
                    q.push(partner[v]);
                }
            }
        }
        return has_unmatched;
    };
    function<bool(int)> find_alt_path = [&](int u) {
        for(int& i = adj_ptr[u]; i < g.adj[u].size(); i++) {
            int v = g.adj[u][i];
            if(partner[v] == -1 or (d[partner[v]] == d[u] + 1 and find_alt_path(partner[v]))) {
                partner[v] = u;
                return true;
            }
        }
        return false;
    };
    while(make_level_graph()) {
        fill(adj_ptr.begin(), adj_ptr.end(), 0);
        for(int u = Index; u < matched.size(); u++) {
            if(not matched[u] and find_alt_path(u)) {
                matched[u] = true;
            }
        }
    }
    auto find_vertex_cover = [&]() {
        vector<int> coverL(g.L + Index), coverR(g.R + Index);
        for(int u = Index; u < coverL.size(); u++) {
            coverL[u] = d[u] == -1;
        }
        for(int v = Index; v < coverR.size(); v++) {
            coverR[v] = partner[v] != -1 and not coverL[partner[v]];
        }
    };
    return partner;
}
