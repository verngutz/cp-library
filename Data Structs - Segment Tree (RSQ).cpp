#include "Data Structs - Segment Tree.cpp"
enum class mode { inc, set };
template <typename T, mode m> struct rsq_segtree : public segtree<T, T> {
    static constexpr auto dcomb = m == mode::inc ? plus<T>() : [](T x, T y) { return y; };
    static constexpr auto lcomb = m == mode::inc
        ? [](T st, T delta, int s, int e) { return st + delta * (e - s); }
        : [](T st, T delta, int s, int e) { return delta * (e - s); };
    rsq_segtree(const vector<T>& a) : segtree<T, T>(0, plus<T>(), 0, dcomb, lcomb, a) {}
    rsq_segtree(int size) : segtree<T, T>(0, plus<T>(), 0, dcomb, lcomb, size) {}
};
