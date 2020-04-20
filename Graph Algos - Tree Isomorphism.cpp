#include "Strings - Hashing.cpp"
#include "Graph Algos - Tree Center.cpp"
template <bool Index> pair<uint64_t, uint64_t> make_hashes(graph<0, edge, Index>& t, int u, int from) {
    static vector<pair<uint64_t, uint64_t>> subtree_hash;
    subtree_hash.resize(t.adj.size());
    int nchildren = 0;
    for(int e : t[u]) {
        if(t(e).v != from) {
            make_hashes(t, t(e).v, u);
            nchildren++;
        }
    }
    if(nchildren == 0) {
        return subtree_hash[u] = {1, 1};
    } else {
        sort(t[u].begin(), t[u].end(), [](int e1, int e2) {
            return subtree_hash[t(e1).v] < subtree_hash[t(e2).v];
        });
        uint64_t h1 = 0, h2 = 0;
        for(int e : t[u]) {
            if(t(e).v != from) {
                h1 = hash1<>::add(hash1<>::mul(h1, hash1<>::X), subtree_hash[t(e).v].first);
                h2 = hash2<>::add(hash2<>::mul(h2, hash2<>::X), subtree_hash[t(e).v].second);
            }
        }
        return subtree_hash[u] = {h1, h2};
    }
}
template <bool Index> vector<pair<uint64_t, uint64_t>> make_hashes(graph<0, edge, Index>& t) {
    vector<pair<uint64_t, uint64_t>> rooted_tree_hashes;
    for(int c : get_centers(t)) {
        rooted_tree_hashes.push_back(make_hashes(t, c, -1));
    }
    return rooted_tree_hashes;
}
template <bool Index> bool isomorphic(graph<0, edge, Index>& t1, graph<0, edge, Index>& t2) {
    bool ans = false;
    for(auto h1 : make_hashes(t1)) {
        for(auto h2 : make_hashes(t2)) {
            ans |= h1 == h2;
        }
    }
    return ans;
}