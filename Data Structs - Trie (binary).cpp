#include <bits/stdc++.h>
#include "Data Structs - Trie.cpp"
using namespace std;
template <typename T> struct int_iterator {
    using type = T;
    static constexpr int start = numeric_limits<T>::digits - 1, step = -1;
    static constexpr int end(T x) { return -1; }
    static inline bool at(T x, int i) { return x & (T(1) << i); }
};
template <typename T> using binary_trie_base = trie<2, 0, int_iterator<T>>;
template <typename T> struct binary_trie : public binary_trie_base<T> {
    using it = int_iterator<T>;
    T min_xor(T x = 0) {
        if(this->empty()) {
            return x;
        } else {
            binary_trie_base<T>* t = this;
            T ans = 0;
            for(int i = it::start; i != it::end(x); i += it::step) {
                if(t->get(it::at(x, i))) {
                    t = t->get(it::at(x, i));
                } else {
                    t = t->get(!it::at(x, i));
                    ans += T(1) << i;
                }
            }
            return ans;
        }
    }
    T max_xor(T x = 0) { return ~min_xor(~x); }
    T mex(T x = 0) {
        binary_trie_base<T>* t = this;
        T ans = 0;
        for(int i = it::start; i != it::end(x) and t and t->get(it::at(x, i)); i += it::step) {
            if(t->get(it::at(x, i))->size < T(1) << i) {
                t = t->get(it::at(x, i));
            } else {
                t = t->get(!it::at(x, i));
                ans += T(1) << i;
            }
        }
        return ans;
    }
};
