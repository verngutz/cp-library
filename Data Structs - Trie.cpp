#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
template <typename string_t = string, int string_start = 0, int string_move = 1>
class trie {
private:
    int sz, n_end;
    map<char, trie*> children;
    bool depth_valid;
    int depth;
    bool in_range(const string_t& s, int i) {
        return string_move > 0 ? i < s.size() : i >= 0;
    }
    trie* node(const string_t& s, int i = string_start) {
        if(in_range(s, i)) {
            return has(s[i]) ? get(s[i])->node(s, i + string_move) : nullptr;
        } else {
            return this;
        }
    }
    void remove(char c) {
        delete children[c];
        children.erase(c);
    }
    void compute_depth() {
        depth = 0;
        for(auto& c : children) {
            depth = max(depth, c.second->get_depth() + 1);
        }
        depth_valid = true;
    }
public:
    trie() : sz(0), n_end(0), depth_valid(false), depth(0) {}
    int size() {
        return sz;
    }
    int n_ending() {
        return n_end;
    }
    int get_depth() {
        if(!depth_valid) {
            compute_depth();
        }
        return depth;
    }
    bool has(char c) {
        return children.count(c);
    }
    trie*& get(char c) {
        return children[c];
    }
    trie* insert(const string_t& s, int i = string_start) {
        sz++;
        if(in_range(s, i)) {
            (has(s[i]) ? get(s[i]) : get(s[i]) = new trie())->insert(s, i + string_move);
            depth_valid = false;
        } else {
            n_end++;
        }
        return this;
    }
    trie* erase(const string_t& s, int i = string_start) {
        sz--;
        if(in_range(s, i)) {
            assert(has(s[i]));
            if(get(s[i])->erase(s, i + string_move)->size() == 0) {
                remove(s[i]);
            }
            depth_valid = false;
        } else {
            n_end--;
        }
        return this;
    }
    // count t ϵ T such that s = t
    int count(const string_t& s, int i = string_start) {
        return node(s, i) ? node(s, i)->n_end : 0;
    }
    // count t ϵ T such that s is a prefix of t
    int n_ext(const string_t& s, int i = string_start) {
        return node(s, i) ? node(s, i)->size() : 0;
    }
    // count t ϵ T such that t is a prefix of s
    int n_pre(const string_t& s, int i = string_start) {
        return n_end + (in_range(s, i) and has(s[i]) ? get(s[i])->n_pre(s, i + string_move) : 0);
    }
    // max LCP(s, t) for all t ϵ T
    int lcp(const string_t& s, int i = string_start) {
        return in_range(s, i) and has(s[i]) ? 1 + get(s[i])->lcp(s, i + string_move) : 0;
    }
    typedef trie<string_t, string_start, string_move> self_type;
#ifdef DEBUG
    template <typename Function>
    void typecheck(const Function& f) {
        using actual_type = typename callable_traits<Function>::function_type;
        using expected_type = typename callable_traits<void(const pair<char, self_type*>&)>::function_type;
        static_assert(is_same<actual_type, expected_type>::value, "trie traverse function must be void(const pair<char, trie*>&)");
    }
#endif
    template <typename PreFunction, typename PostFunction, typename LeafFunction, typename CmpFunction>
    void traverse(const PreFunction& pre, const PostFunction& post, const LeafFunction& leaf, const CmpFunction& cmp, char cur = 0) {
    #ifdef DEBUG
        typecheck(pre);
        typecheck(post);
        typecheck(leaf);
        using actual_type = typename callable_traits<CmpFunction>::function_type;
        using expected_type = typename callable_traits<bool(const pair<char, self_type*>&, const pair<char, self_type*>&)>::function_type;
        static_assert(is_same<actual_type, expected_type>::value, "trie 'cmp' must be bool(const pair<char, trie*>, const pair<char, trie*>)");
    #endif
        vector<pair<char, self_type*>> to_proc;
        for(auto& c : children) {
            to_proc.push_back(c);
        }
        sort(to_proc.begin(), to_proc.end(), cmp);
        for(const auto& p : to_proc) {
            pre(p);
            p.second->traverse(pre, post, leaf, cmp, p.first);
            post(p);
        }
        if(to_proc.empty()) {
            leaf({cur, this});
        }
    }
    template <typename PreFunction, typename PostFunction, typename LeafFunction>
    void traverse(const PreFunction& pre, const PostFunction& post, const LeafFunction& leaf, char cur = 0) {
        traverse(pre, post, leaf, [](const pair<char, self_type*>& a, const pair<char, self_type*>& b) {
            return a.first < b.first;
        }, cur);
    }
};
