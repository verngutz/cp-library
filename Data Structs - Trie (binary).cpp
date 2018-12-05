#include <bits/stdc++.h>
#include "Data Structs - Trie.cpp"
using namespace std;
template <typename T> constexpr int n_bits() { return numeric_limits<T>::digits; }
template <typename T> using binary_trie_base = trie<2, 0, bitset<n_bits<T>()>, n_bits<T>() - 1, -1>;
template <typename T> struct binary_trie : public binary_trie_base<T> {
    using bitset_t = bitset<n_bits<T>()>;
    void insert(T x) { binary_trie_base<T>::insert(bitset_t(x)); }
    void erase(T x) { binary_trie_base<T>::erase(bitset_t(x)); }
    int count(T x) { return binary_trie_base<T>::count(bitset_t(x)); }
    T min_xor(const bitset_t& s) {
        if(this->size == 0) {
            return T(s.to_ullong());
        } else {
            binary_trie_base<T>* t = this;
            T ans = 0;
            for(int i = n_bits<T>() - 1; i >= 0; i--) {
                ans += t->get(s[i]) ? 0 : T(1) << i;
                t = t->get(s[i]) ? t->get(s[i]) : t->get(!s[i]);
            }
            return ans;
        }
    }
    T min_xor(T x = 0) { return min_xor(bitset_t(x)); }
    T max_xor(T x = 0) { return ~min_xor(~x); }
    T mex(const bitset_t& s, int i = n_bits<T>() - 1) {
        binary_trie_base<T>* t = this;
        T ans = 0;
        for(int i = n_bits<T>() - 1; i >= 0 and t and t->get(s[i]); i--) {
            if(t->get(s[i])->size < T(1) << i) {
                t = t->get(s[i]);
            } else {
                t = t->get(!s[i]);
                ans += T(1) << i;
            }
        }
        return ans;
    }
    T mex(T x = 0) { return mex(bitset_t(x)); }
};
