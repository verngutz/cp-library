#include "Data Structs - Segment Tree.cpp"
template <typename T>
struct rsq_segtree : public segtree<T, T> {
    static constexpr auto range_increment = plus<T>();
    static constexpr auto range_increment_lazy = [](T st, T delta, int s, int e) {
        return st + delta * (e - s + 1);
    };
    static constexpr auto range_set = [](T x, T y) { return y; };
    static constexpr auto range_set_lazy = [](T st, T delta, int s, int e) {
        return delta * (e - s + 1);
    };
    rsq_segtree(const vector<T>& a) : segtree<T, T>(0, plus<T>(), 0, range_increment, range_increment_lazy, a) {}
    rsq_segtree(int size) : segtree<T, T>(0, plus<T>(), 0, range_increment, range_increment_lazy, size) {}
};
