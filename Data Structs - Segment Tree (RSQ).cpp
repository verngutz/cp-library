#include "Data Structs - Segment Tree.cpp"
enum mode { increment, set_value };
template <typename T, mode m> struct rsq_segtree : public segtree<T, T> {
    static constexpr auto dcomb = m == increment ? [](T x, T y) { return x + y; } : [](T x, T y) { return y; };
    static constexpr auto lcomb = m == increment
        ? [](T st, T delta, int s, int e) { return st + delta * (e - s + 1); }
        : [](T st, T delta, int s, int e) { return delta * (e - s + 1); };
    rsq_segtree(const vector<T>& a) : segtree<T, T>(0, plus<T>(), 0, dcomb, lcomb, a) {}
    rsq_segtree(int size) : segtree<T, T>(0, plus<T>(), 0, dcomb, lcomb, size) {}
};
