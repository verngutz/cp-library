#include <bits/stdc++.h>
using namespace std;
// NOTE: one-indexed
template <typename T>
struct bit {
    vector<T> t;
    bit(int n) : t(n + 1) {}
    int size() {
        return t.size() - 1;
    }
    void add(int i, T value) {
        for(int j = i; j < t.size(); j += j & -j) {
            t[j] += value;
        }
    }
    T sum(int i) {
        T res = 0;
        for(int j = i; j > 0; j -= j & -j) {
            res += t[j];
        }
        return res;
    }
    T sum(int L, int R) {
        return sum(R) - sum(L - 1);
    }
};