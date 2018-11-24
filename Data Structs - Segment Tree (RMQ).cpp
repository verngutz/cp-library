#include <bits/stdc++.h>
#include "Data Structs - Segment Tree.cpp"
using namespace std;
template <typename T>
struct rmq_segtree : public segtree<T, T> {
    static constexpr const T inf = numeric_limits<T>::max();
    static constexpr auto rmq_lazy = [](T st, T delta, int s, int e) {
        return st + delta;
    };
    rmq_segtree(const vector<T>& a) : segtree<T, T>(inf, min, 0, plus<T>(), rmq_lazy, a) {}
    rmq_segtree(int size) : segtree<T, T>(inf, min, 0, plus<T>(), rmq_lazy, size) {}
};
