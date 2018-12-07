#include <bits/stdc++.h>
using namespace std;
struct string_iterator {
    using type = string;
    static constexpr int start = 0, step = 1;
    static inline int end(string s) { return s.size(); }
    static inline char at(string s, int i) { return s[i]; }
};
template <int alpha_size, char alpha_start, typename it = string_iterator>
struct trie {
    int size, n_ending, height;
    trie* children[alpha_size];
    trie() : size(0), n_ending(0), height(0) {
        for(trie*& t : children) {
            t = nullptr;
        }
    }
    void clear() {
        for(trie*& t : children) {
            delete t;
            t = nullptr;
        }
        size = 0, n_ending = 0, height = 0;
    }
    ~trie() {
        clear();
    }
    bool empty() {
        return size == 0;
    }
    trie*& get(char c) {
        return children[c - alpha_start];
    }
    trie*& operator[](char c) {
        return get(c);
    }
    trie* operator[](const typename it::type& s) {
        auto t = this;
        for(int i = it::start; i != it::end(s); i += it::step) {
            t = t ? t->get(it::at(s, i)) : nullptr;
        }
        return t;
    }
    void remove(char c) {
        delete children[c];
        children[c] = nullptr;
    }
    trie* insert(const typename it::type& s, int i = it::start) {
        size++;
        if(i != it::end(s)) {
            (get(it::at(s, i)) ? get(it::at(s, i)) : get(it::at(s, i)) = new trie())->insert(s, i + it::step);
            height = max(height, get(it::at(s, i))->height + 1);
        } else {
            n_ending++;
        }
        return this;
    }
    trie* erase(const typename it::type& s, int i = it::start) {
        size--;
        if(i != it::end(s)) {
            get(it::at(s, i))->erase(s, i + it::step)->empty() ? remove(it::at(s, i)) : void();
            height = accumulate(children.begin(), children.end(), 0, [](int h, trie* t) {
                return t ? max(h, t->height + 1) : h;
            });
        } else {
            n_ending--;
        }
        return this;
    }
    // count t ϵ T such that s = t
    int count(const typename it::type& s) {
        auto t = (*this)[s];
        return t ? t->n_ending : 0;
    }
    // count t ϵ T such that s is a prefix of t
    int n_suffixes(const typename it::type& s) {
        auto t = (*this)[s];
        return t ? t->size : 0;
    }
    // count t ϵ T such that t is a prefix of s
    int n_prefixes(const typename it::type& s) {
        auto t = this;
        int ans = t->n_ending;
        for(int i = it::start; i != it::end(s); i += it::step) {
            t = t ? t->get(it::at(s, i)) : nullptr;
            ans += t ? t->n_ending : 0;
        }
        return ans;
    }
    // max LCP(s, t) for all t ϵ T
    int lcp(const typename it::type& s) {
        auto t = this;
        int ans = 0;
        for(int i = it::start; i != it::end(s); i += it::step) {
            t = t ? t->get(it::at(s, i)) : nullptr;
            ans += t ? 1 : 0;
        }
        return ans;
    }
};
