#include <bits/stdc++.h>
using namespace std;
struct string_iterator {
    using type = string;
    int i = 0;
    bool operator<(const string& s) const { return i < s.size(); }
    string_iterator& operator++() { i++; return *this; }
    char operator()(const string& s) { return s[i]; }
    friend int operator-(const string& s, const string_iterator& it) { return s.size() - it.i; }
};
template <int alpha_size, char alpha_start, typename iterator = string_iterator>
struct trie {
    int size, n_ending, height;
    trie* children[alpha_size];
    trie() : size(0), n_ending(0), height(0) {
        for(trie*& t : children) {
            t = nullptr;
        }
    }
    trie(trie&& t) { *this = move(t); }
    trie& operator=(trie&& t) {
        size = t.size, n_ending = t.n_ending, height = t.height;
        for(int i = 0; i < alpha_size; i++) {
            children[i] = t.children[i];
            t.children[i] = nullptr;
        }
        return *this;
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
    trie* operator[](const typename iterator::type& s) {
        trie* t = this;
        for(iterator i; i < s; ++i) {
            t = t ? (*t)[i(s)] : nullptr;
        }
        return t;
    }
    void remove(char c) {
        delete children[c];
        children[c] = nullptr;
    }
    trie* insert(const typename iterator::type& s) {
        trie* t = this;
        for(iterator i; i < s; ++i) {
            t->size++;
            t->height = max(height, s - i);
            t = (*t)[i(s)] ?: ((*t)[i(s)] = new trie());
        }
        t->n_ending++;
        return this;
    }
    trie* erase(const typename iterator::type& s, const iterator& i = {}) {
        size--;
        if(i < s) {
            get(i(s)) and get(i(s))->erase(s, ++iterator(i))->empty() ? remove(i(s)) : void();
            height = accumulate(children, children + alpha_size, 0, [](int h, trie* t) {
                return t ? max(h, t->height + 1) : h;
            });
        } else {
            n_ending--;
        }
        return this;
    }
    // count t ϵ T such that s = t
    int count(const typename iterator::type& s) {
        trie* t = (*this)[s];
        return t ? t->n_ending : 0;
    }
    // count t ϵ T such that s is a prefix of t
    int n_suffixes(const typename iterator::type& s) {
        trie* t = (*this)[s];
        return t ? t->size : 0;
    }
    // count t ϵ T such that t is a prefix of s
    int n_prefixes(const typename iterator::type& s) {
        trie* t = this;
        int ans = t->n_ending;
        for(iterator i; i < s; ++i) {
            t = t ? (*t)[i(s)] : nullptr;
            ans += t ? t->n_ending : 0;
        }
        return ans;
    }
    // max LCP(s, t) for all t ϵ T
    int lcp(const typename iterator::type& s) {
        trie* t = this;
        int ans = 0;
        for(iterator i; i < s; ++i) {
            t = t ? (*t)[i(s)] : nullptr;
            ans += t ? 1 : 0;
        }
        return ans;
    }
};
