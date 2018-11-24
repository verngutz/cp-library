#include <bits/stdc++.h>
#include "Graph - Transpose Graph (unweighted).cpp"
using namespace std;
using ll = long long;
ll longest_path(graph<1>& g) {
    graph<1> t = transpose(g);
    vector<ll> memo(g.n + 1, -1);
    vector<int> pred(g.n + 1, -1);
    function<ll(int)> longest_path = [&](int v) {
        ll& ans = memo[v];
        if(ans == -1) {
            ans = 0;
            for(auto [i, v, u] : t.adj[v]) {
                if(ans < longest_path(u) + 1) {
                    ans = longest_path(u) + 1;
                    pred[v] = u;
                }
            }
        }
        return ans;
    };
    ll ans = 0;
    for(int u = 1; u <= g.n; u++) {
        ans = max(ans, longest_path(u));
    }
    return ans;
}
