#include <bits/stdc++.h>
#include "Flows - Max Flow Structure.cpp"
using namespace std;
template <typename T, bool Index> T max_flow(flow_graph<T, Index>& g, int s, int t) {
    vector<int> height(g.adj.size()), counter(2 * g.size());
    vector<T> excess(g.adj.size());
    vector<bool> active(g.adj.size());
    queue<int> q;
    auto push = [&](int u, int e, int df) {
        g(e).f += df, excess[g(e).v] += df;
        g(e ^ 1).f -= df, excess[u] -= df;
        if(excess[g(e).v] and not active[g(e).v] and g(e).v != s and g(e).v != t) {
            q.push(g(e).v), active[g(e).v] = true;
        }
    };
    auto discharge = [&](int u) {
        for(int j = 0; j < g[u].size() and excess[u]; j++) {
            if(height[u] > height[g(g[u][j]).v] and g(g[u][j]).resid() > 0) {
                push(u, g[u][j], min(excess[u], g(g[u][j]).resid()));
            }
        }
    };
    auto relabel = [&](int u) {
        if(counter[height[u]] == 1) {
            for(int v = Index; v < g.adj.size(); v++) {
                if(v != s and height[v] >= height[u]) {
                    counter[height[v]]--;
                    counter[height[v] = max(height[v], g.adj.size())]++;
                }
            }
        } else {
            counter[height[u]]--;
            height[u] = 2 * g.size() - 1;
            for(int e : g[u]) if(g(e).resid() > 0) {
                height[u] = min(height[u], height[g(e).v] + 1);
            }
            counter[height[u]]++;
        }
    };
    height[s] = g.size();
    for(int e : g[s]) {
        push(s, e, g(e).c);
    }
    while(not q.empty()) {
        int u = q.front(); q.pop(), active[u] = false;
        discharge(u);
        if(excess[u] and not active[u]) {
            relabel(u);
            q.push(u), active[u] = true;
        }
    }
    return excess[t];
}
