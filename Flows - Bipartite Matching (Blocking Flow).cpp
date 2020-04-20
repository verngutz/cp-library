#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
struct graph {
    int L, R;
    vector<vector<int>> adj;
    graph(int L, int R) : L(L), R(R), adj(L + 1) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
};
vector<int> max_matching(graph& g) {
    vector<bool> matched(g.L + 1);
    vector<int> partner(g.R + 1), d(g.L + 1), adj_ptr(g.L + 1);
    auto make_level_graph = [&]() {
        fill(d.begin(), d.end(), -1);
        queue<int> q;
        for(int u = 1; u <= g.L; u++) {
            if(not matched[u]) {
                d[u] = 0;
                q.push(u);
            }
        }
        bool has_unmatched = false;
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g.adj[u]) {
                if(not partner[v]) {
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
            if(not partner[v] or (d[partner[v]] == d[u] + 1 and find_alt_path(partner[v]))) {
                partner[v] = u;
                return true;
            }
        }
        return false;
    };
    while(make_level_graph()) {
        fill(adj_ptr.begin(), adj_ptr.end(), 0);
        for(int u = 1; u <= g.L; u++) {
            if(not matched[u] and find_alt_path(u)) {
                matched[u] = true;
            }
        }
    }
    return partner;
}
