#include <bits/stdc++.h>
#include "Data Structs - Trie.cpp"
using namespace std;
template <typename T> struct int_iterator {
    using type = T;
    int i = numeric_limits<T>::digits - 1;
    bool operator<(const T& x) const { return i >= 0; }
    int_iterator& operator++() { i--; return *this; }
    char operator()(const T& x) { return (x >> i) & 1; }
    friend int operator-(const T& x, const int_iterator& it) { return it.i + 1; }
};
template <typename T> using binary_trie_base = trie<2, 0, int_iterator<T>>;
template <typename T> struct binary_trie : public binary_trie_base<T> {
    using iterator = int_iterator<T>;
    T min_xor(T x = 0) {
        if(this->empty()) {
            return x;
        } else {
            binary_trie_base<T>* t = this;
            T ans = 0;
            for(iterator i; i < x; ++i) {
                if(t->get(i(x))) {
                    t->get(i(x))
                } else {
                    t->get(!i(x));
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
        for(iterator i; i < x and t and t->get(i(x)); ++i) {
            if(t->get(i(x))->size < T(1) << i) {
                t = t->get(i(x));
            } else {
                t = t->get(!i(x));
                ans += T(1) << i;
            }
        }
        return ans;
    }
};
