#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
#define WEIGHTED
#define DIST_QUERIES
#define PATH_QUERIES
// NOTE: one-indexed
template <typename T>
class lca_tree {
private:
    int root;
    vector<int> lg, depth;
#ifdef WEIGHTED
    struct edge { int v, w; };
    vector<vector<edge>> adj;
    int v(const edge& e) { return e.v; }
    int w(const edge& e) { return e.w; }
#else
    vector<vector<int>> adj;
    int v(int v) { return v; }
    int w(int v) { return 1; }
#endif
    vector<vector<int>> par;
#ifdef DIST_QUERIES
    vector<int> root_dist;
#endif
#ifdef PATH_QUERIES
    T zero;
    function<T(T, T)> combine;
    bool vertex_weighted;
    vector<vector<T>> st;
#endif
    bool built;
    void dfs(int u, int from) {
        for(const auto& e : adj[u]) {
            if(v(e) != from) {
                par[v(e)].push_back(u);
                depth[v(e)] = depth[u] + 1;
            #ifdef DIST_QUERIES
                root_dist[v(e)] = root_dist[u] + w(e);
            #endif
            #ifdef PATH_QUERIES
                st[v(e)].push_back(w(e));
            #endif
                build_ancestors(v(e));
                dfs(v(e), u);
            }
        }
    }
    void build_ancestors(int u) {
        for(int pow2 = 1; pow2 <= lg[depth[u]]; pow2++) {
            par[u].push_back(par[par[u][pow2-1]][pow2-1]);
        #ifdef PATH_QUERIES
            st[u].push_back(combine(st[u][pow2-1], st[par[u][pow2-1]][pow2-1]));
        #endif
        }
    }
public:
    const int size;
#ifdef PATH_QUERIES
    lca_tree(int size, T zero, const function<T(T, T)>& combine, bool vertex_weighted = false)
    : zero(zero), combine(combine), size(size), vertex_weighted(vertex_weighted), built(false) {
        root = vertex_weighted ? 0 : 1;
#else
    lca_tree(int size)
    : root(1), size(size) {
#endif
        lg.resize(size + 1);
        depth.resize(size + 1);
        adj.resize(size + 1);
        par.resize(size + 1);
    #ifdef DIST_QUERIES
        root_dist.resize(size + 1);
    #endif
    #ifdef PATH_QUERIES
        st.resize(size + 1);
    #endif
    }
    int get_depth(int u) {
        return depth[u];
    }
#ifdef WEIGHTED
    void link(int u, int v) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
#else
    void link(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
#endif
    void build() {
        lg[0] = -1, lg[1] = 0;
        for(int i = 2; i <= size; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
        depth[root] = 0;
        dfs(root, -1);
        built = true;
    }
    int kth_ancestor(int u, int k) {
        assert(built);
        assert(k <= depth[u]);
        for(int pow2 = 0; k > 0; k >>= 1, pow2++) {
            u = k & 1 ? par[u][pow2] : u;
        }
        return u;
    }
    template <typename Function>
    int bsearch_ancestor(int u, const Function& can, int limit = -1) {
    #ifdef DEBUG
        using actual_type = typename callable_traits<Function>::function_type;
        using expected_type = typename callable_traits<bool(int)>::function_type;
        static_assert(is_same<actual_type, expected_type>::value);
    #endif
        assert(built);
        if(limit == -1) limit = depth[u];
        int bound = kth_ancestor(u, limit);
        if(can(bound)) return bound;
        for(int pow2 = lg[limit]; pow2 >= 0; pow2--) {
            u = can(par[u][pow2]) ? par[u][pow2] : u;
        }
        return u;
    }
    int lca(int u, int v) {
        assert(built);
        if(depth[u] > depth[v]) swap(u, v);
        v = kth_ancestor(v, depth[v] - depth[u]);
        for(int pow2 = lg[depth[u]]; pow2 >= 0; pow2--) {
            if((1 << pow2) <= depth[u] and par[u][pow2] != par[v][pow2]) {
                u = par[u][pow2], v = par[v][pow2];
            }
        }
        return u == v ? u : par[u][0];
    }
#ifdef DIST_QUERIES
    int dist(int u, int v) {
        return root_dist[u] + root_dist[v] - 2 * root_dist[lca(u, v)];
    }
#endif
#ifdef PATH_QUERIES
    T level_query(int u, int k) {
        assert(built);
        assert(k <= depth[u]);
        T ans = zero;
        for(int pow2 = 0; k > 0; k >>= 1, pow2++) {
            ans = k & 1 ? combine(ans, st[u][pow2]) : ans;
            u = k & 1 ? par[u][pow2] : u;
        }
        return ans;
    }
    T path_query(int u, int v) {
        assert(built);
        int l = lca(u, v);
        T ans = combine(level_query(u, depth[u] - depth[l]), level_query(v, depth[v] - depth[l]));
        return vertex_weighted ? combine(ans, st[l][0]) : ans;
    }
#endif
#ifdef WEIGHTED
    void add_node(int parent, const edge& e, bool build = false) {
#else
    void add_node(int parent, int e, bool build = false) {
#endif
        adj[parent].push_back(e);
        depth[v(e)] = depth[parent] + 1;
    #ifdef PATH_QUERIES
        st[v(e)].push_back(w(e));
    #endif
        if(build) {
            par[v(e)].push_back(parent);
            build_ancestors(v(e));
        }
    }
    void remove_leaf(int u) {
        vector<int>().swap(par[u]);
    }
};
