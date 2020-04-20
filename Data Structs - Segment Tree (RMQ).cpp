#include <bits/stdc++.h>
#include "Data Structs - Segment Tree.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
template <typename T> struct rmq_segtree : public segtree<T, T> {
    static constexpr auto rmq = [](const T& x, const T& y) { return min(x, y); };
    static constexpr auto rmq_lazy = [](const T& st, const T& delta, int s, int e) { return st + delta; };
    rmq_segtree(const vector<T>& a) : segtree<T, T>(a, {lim<T>::max(), rmq}, {0, plus<T>()}, rmq_lazy) {}
    rmq_segtree(int size) : segtree<T, T>(size, {lim<T>::max(), rmq}, {0, plus<T>()}, rmq_lazy) {}
};
