#include <bits/stdc++.h>
#include "Binary Search.cpp"
using namespace std;
using ll = long long;
// maintain an upper/lower hull L of lines y = mx + b
// query for y(x) such that y(x) is minimum/maximum over all lines y in L
// assumes lines are inserted in non-increasing/non-decreasing order of m
// minimization by default, call constructor with greater<ll>() for maximization
struct cht {
    struct line {
        ll m, b, intersection;
        ll eval(ll x) const { return m * x + b; }
        ll cross(const line& l) const { return (l.b - b) / (m - l.m); }
        bool operator<(const line& l) const { return m < l.m; }
        bool operator<(const ll x) const { return intersection < x; }
    };
    multiset<line, less<>> h;
    const function<bool(ll, ll)> cmp;
    cht(const function<bool(ll, ll)>& cmp = less<ll>()) : cmp(cmp) {}
    const line& l1() { return *h.rbegin(); }
    const line& l2() { return *++h.rbegin(); }
    void pop() { h.erase(--h.end()); }
    void add(ll m, ll b) {
        if(h.empty()) {
            h.insert({m, b, numeric_limits<ll>::min()});
        } else if(m != l1().m or cmp(b, l1().b)) {
            if(m == l1().m) pop();
            while(h.size() >= 2 and l1().cross({m, b}) <= l1().cross(l2())) pop();
            h.insert({m, b, l1().cross({m, b})});
        }
    }
    ll opt(ll x) {
        assert(!h.empty());
        return lt(h, x)->eval(x);
    }
};
