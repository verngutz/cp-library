#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
// go through all ways to form unordered pairs from [0, n - 1]
// f is the action to do on every such pairing p
// p[0] is paired with p[n-1], p[1] with p[n-2], etc.
// runs in n (n - 2) (n - 4) ... time
void paired_permutations(int n, const function<void(vector<int>&)>& f) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<void(int)> rb = [&](int i) {
        if(i == n / 2) {
            f(p);
        } else {
            for(int j = i + 1; j < n - i; j++) {
                swap(p[j], p[n - 1 - i]);
                rb(i + 1);
                swap(p[j], p[n - 1 - i]);
            }
        }
    };
    if(n % 2) {
        for(int i = 0; i < n; i++) {
            swap(p[i], p[n / 2]);
            rb(0);
            swap(p[i], p[n / 2]);
        }
    } else {
        rb(0);
    }
}
