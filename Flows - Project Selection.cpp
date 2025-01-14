#include "Graph Structures - Edge (unweighted).cpp"
#include "Flows - Max Flow (Blocking Flow).cpp"
using ll = long long;
template <typename T, bool Index> ll project_selection(graph<1, edge, Index>& g, const vector<T>& w) {
    flow_graph<T, Index> f(g.size() + 2);
    int s = g.size() + Index, t = g.size() + 1 + Index;
    for(int i = Index; i < w.size(); i++) {
        f.add_edge({s, i, max(w[i], T(0))});
        f.add_edge({i, t, max(-w[i], T(0))});
    }
    for(auto [u, v] : g.edges) {
        f.add_edge({u, v, lim<T>::max()});
    }
    ll sum_positive = 0;
    for(const T& x : w) {
        sum_positive += max(x, T(0));
    }
    return sum_positive - max_flow(f, s, t);
}
