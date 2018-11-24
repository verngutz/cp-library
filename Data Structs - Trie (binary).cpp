#include <bits/stdc++.h>
#include "Data Structs - Trie.cpp"
using namespace std;
template <typename T>
class binary_trie {
private:
    static const int BITS = numeric_limits<T>::digits;
    using bitset_t = bitset<BITS>;
    using trie_t = trie<bitset_t, BITS - 1, -1>;
    trie_t* t;
    T min_xor(trie_t* t, const bitset_t& s, int i = BITS - 1) {
        if(i >= 0) {
            if(t->has(s[i])) {
                return min_xor(t->get(s[i]), s, i - 1);
            } else {
                return (T(1) << i) | min_xor(t->get(~s[i]), s, i - 1);
            }
        } else {
            return 0;
        }
    }
    T mex(trie_t* t, const bitset_t& s, int i = BITS - 1) {
        if(i >= 0 and t and t->has(s[i])) {
            if(t->get(s[i])->size() < (T(1) << i)) {
                return mex(t->get(s[i]), s, i - 1);
            } else {
                return (T(1) << i) | mex(t->get(~s[i]), s, i - 1);
            }
        } else {
            return 0;
        }
    }
public:
    binary_trie() : t(new trie_t()) {}
    int size() {
        return t->size();
    }
    binary_trie& insert(T x) {
        t->insert(bitset_t(x));
        return *this;
    }
    binary_trie& erase(T x) {
        t->erase(bitset_t(x));
        return *this;
    }
    int count(T x) {
        return t->count(bitset_t(x));
    }
    T min_xor(T x) {
        return min_xor(t, bitset_t(x));
    }
    T max_xor(T x) {
        return ~min_xor(~x);
    }
    T mex(T x = 0) {
        return mex(t, bitset_t(x));
    }
};
