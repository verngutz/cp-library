#include <bits/stdc++.h>
using namespace std;
template <typename T, bool Index> struct bit {
    const int n;
    vector<T> t;
    bit(int n) : n(n), t(n + 1) {}
    void add(int i, T value) {
        for(int j = i + 1 - Index; j <= n; j += j & -j) {
            t[j] += value;
        }
    }
    T sum(int i) {
        T res = 0;
        for(int j = i + 1 - Index; j > 0; j -= j & -j) {
            res += t[j];
        }
        return res;
    }
    T sum(int L, int R) {
        return sum(R) - sum(L - 1);
    }
    void clear() {
        fill(t.begin(), t.end(), 0);
    }
    friend ostream& operator<<(ostream& os, bit& t) {
        os << "[";
        for(int i = Index; i < t.n + Index; i++) {
            if(i != Index) os << ", ";
            os << t.sum(i, i);
        }
        return os << "]";
    }
};
