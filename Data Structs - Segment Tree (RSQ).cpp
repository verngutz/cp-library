#include "Data Structs - Segment Tree.cpp"
enum class mode { inc, set };
template <typename T, mode m> struct rsq_segtree : public segtree<T, T> {
    static constexpr auto dcomb = m == mode::inc
        ? [](const T& x, const T& y) { return x + y; }
        : [](const T& x, const T& y) { return y; };
    static constexpr auto lcomb = m == mode::inc
        ? [](const T& st, const T& delta, int s, int e) { return st + delta * (e - s); }
        : [](const T& st, const T& delta, int s, int e) { return delta * (e - s); };
    rsq_segtree(const vector<T>& a) : segtree<T, T>(a, {0, plus<T>()}, {0, dcomb}, lcomb) {}
    rsq_segtree(int size) : segtree<T, T>(size, {0, plus<T>()}, {0, dcomb}, lcomb) {}
};
