#include <bits/stdc++.h>
#include "Data Structs - Segment Tree.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
enum class mode { inc, set };
template <typename T, mode m> struct rmq_segtree : public segtree<T, T> {
    static constexpr auto rmq = [](const T& x, const T& y) { return min(x, y); };
    static constexpr auto dcomb = m == mode::inc
        ? [](const T& x, const T& y) { return x + y; }
        : [](const T& x, const T& y) { return y; };
    static constexpr auto lcomb = m == mode::inc
        ? [](const T& st, const T& delta, int s, int e) { return st + delta; }
        : [](const T& st, const T& delta, int s, int e) { return delta; };
    rmq_segtree(const vector<T>& a) : segtree<T, T>(a, {lim<T>::max(), rmq}, {0, dcomb}, lcomb) {}
    rmq_segtree(int size) : segtree<T, T>(size, {lim<T>::max(), rmq}, {0, dcomb}, lcomb) {}
};
