#include <bits/stdc++.h>
#include "Flows - Max Flow Structure.cpp"
using namespace std;
template <typename T, bool Index> T max_flow(flow_graph<T, Index>& g, int s, int t) {
    vector<int> d(g.adj.size()), adj_ptr(g.adj.size());
    auto make_level_graph = [&]() {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q({s});
        while(not q.empty()) {
            int u = q.front(); q.pop();
            for(int e : g[u]) {
                if(g(e).resid() > 0 and d[g(e).v] == -1) {
                    d[g(e).v] = d[g(e).u] + 1;
                    q.push(g(e).v);
                }
            }
        }
        return d[t] != -1;
    };
    function<T(int, T)> augment = [&](int u, T b) {
        if(u == t) return b;
        for(int& j = adj_ptr[u]; j < g[u].size(); j++) {
            fedge<T>& e = g(g[u][j]);
            if(T df; d[e.v] == d[u] + 1 and e.resid() > 0 and (df = augment(e.v, min(b, e.resid())))) {
                e.f += df, g(g[u][j] ^ 1).f -= df;
                return df;
            }
        }
        return T(0);
    };
    T ans = 0;
    while(make_level_graph()) {
        fill(adj_ptr.begin(), adj_ptr.end(), 0);
        while(T df = augment(s, numeric_limits<T>::max())) {
            ans += df;
        }
    }
    return ans;
}
