#include <bits/stdc++.h>
#include "Data Structs - Monoid.cpp"
template <typename In, typename Out = In, typename Node = In> struct segtree {
	const int size;
	vector<Node> tree;
    const monoid<Out> m;
    template <typename Leaf, typename Branch>
	segtree(const vector<In>& a, const monoid<Out>& m, const Leaf& leaf, const Branch& branch) 
    : size(a.size()), tree(2 * (size + 1)), m(m) {
        static_assert(is_convertible<decltype(leaf), function<Node(const In&)>>::value);
        static_assert(is_convertible<decltype(branch), function<Node(const Node&, const Node&)>>::value);
		for(int i = 0; i < size; i++) tree[i + size] = leaf(a[i]);
		for(int i = size - 1; i > 0; i--) tree[i] = branch(tree[i << 1], tree[(i << 1) | 1]);
    }
	static constexpr auto identity = [](const auto& x) { return x; };
    segtree(const vector<In>& a, const monoid<Out>& m) : segtree(a, m, identity, m.combine) {}
	template <typename Query = decltype(identity)> 
    Out query(int L, int R, bool inclusive, const Query& query_f = identity) {
        static_assert(is_convertible<decltype(query_f), function<Out(Node&)>>::value);
		assert(L <= R + inclusive);
		Out ans_l = m.identity, ans_r = m.identity;
		for(int a = L + size, b = R + size + inclusive; a < b; a >>= 1, b >>= 1) {
			if(a & 1) ans_l = m.combine(ans_l, query_f(tree[a++]));
			if(b & 1) ans_r = m.combine(query_f(tree[--b]), ans_r);
		}
		return m.combine(ans_l, ans_r);
	}
    template <typename Query = decltype(identity)> 
    Out query(int i, const Query& query_f = identity) { return query(i, i, true, query_f); }
    void update(int i, const In& new_value) {
        static_assert(is_same<Node, In>::value);
        static_assert(is_same<Node, Out>::value);
        for(tree[i += size] = new_value; i >>= 1; )
            tree[i] = m.combine(tree[i << 1], tree[(i << 1) | 1]);
    }
    template <typename UpdateNode> void update(int i, const In& new_value, const UpdateNode& update_node) {
        static_assert(is_convertible<decltype(update_node), function<void(Node&, const In&)>>::value);
        for(update_node(tree[i += size], new_value); i >>= 1; )
            update_node(tree[i], new_value);
    }
    template <typename Leaf, typename Branch> void update(int i, const In& new_value, const Leaf& leaf, const Branch& branch) {
        static_assert(is_convertible<decltype(leaf), function<void(Node&, const In&)>>::value);
        static_assert(is_convertible<decltype(branch), function<void(Node&, const Node&, const Node&, const In&)>>::value);
        for(leaf(tree[i += size], new_value); i >>= 1; )
            branch(tree[i], tree[i << 1], tree[(i << 1) | 1], new_value);
    }
};
