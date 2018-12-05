#include <bits/stdc++.h>
using namespace std;
template <int alpha_size, char alpha_start, typename string_t = string, int i_start = 0, int i_step = 1>
struct trie {
    int size, n_ending, height;
    vector<trie*> children;
    trie() : size(0), n_ending(0), height(0), children(alpha_size) {}
    ~trie() {
        for(trie* t : children) {
            delete t;
        }
    }
    trie*& get(char c) {
        return children[c - alpha_start];
    }
    trie*& operator[](char c) {
        return get(c);
    }
    trie* operator[](const string_t& s) {
        auto t = this;
        for(int i = i_start; 0 <= i and i < s.size(); i += i_step) {
            t = t ? t->get(s[i]) : nullptr;
        }
        return t;
    }
    void remove(char c) {
        delete children[c];
        children[c] = nullptr;
    }
    trie* insert(const string_t& s, int i = i_start) {
        size++;
        if(0 <= i and i < s.size()) {
            (get(s[i]) ? get(s[i]) : get(s[i]) = new trie())->insert(s, i + i_step);
            height = max(height, get(s[i])->height + 1);
        } else {
            n_ending++;
        }
        return this;
    }
    trie* erase(const string_t& s, int i = i_start) {
        size--;
        if(0 <= i and i < s.size()) {
            get(s[i])->erase(s, i + i_step)->size ? void() : remove(s[i]);
            height = accumulate(children.begin(), children.end(), 0, [](int h, trie* t) {
                return t ? max(h, t->height + 1) : h;
            });
        } else {
            n_ending--;
        }
        return this;
    }
    // count t ϵ T such that s = t
    int count(const string_t& s) {
        auto t = (*this)[s];
        return t ? t->n_ending : 0;
    }
    // count t ϵ T such that s is a prefix of t
    int n_suffixes(const string_t& s) {
        auto t = (*this)[s];
        return t ? t->size : 0;
    }
    // count t ϵ T such that t is a prefix of s
    int n_prefixes(const string_t& s) {
        auto t = this;
        int ans = t->n_ending;
        for(int i = i_start; 0 <= i and i < s.size(); i += i_step) {
            t = t ? t->get(s[i]) : nullptr;
            ans += t ? t->n_ending : 0;
        }
        return ans;
    }
    // max LCP(s, t) for all t ϵ T
    int lcp(const string_t& s) {
        auto t = this;
        int ans = 0;
        for(int i = i_start; 0 <= i and i < s.size(); i += i_step) {
            t = t ? t->get(s[i]) : nullptr;
            ans += t ? 1 : 0;
        }
        return ans;
    }
};
