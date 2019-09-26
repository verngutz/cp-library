#include "Data Structs - Segment Tree.cpp"
template <typename T> struct line_flag {
    T a, b, c;
    line_flag() : a(0), b(0), c(0) {}
    line_flag(T a, T b, T c) : a(a), b(b), c(c) {}
    line_flag(T i) : a(1), b(-2 * i + 1), c(i * i - i) {}
    T eval(T x) const { return (a * x * x + b * x + c) / 2; }
    line_flag& operator+=(const line_flag<T>& f) { a += f.a, b += f.b, c += f.c; return *this; }
    line_flag operator+(const line_flag<T>& f) const { return line_flag(*this) += f; }
};
template <typename T> using line_segtree_base = segtree<T, line_flag<T>>;
template <typename T> struct line_segtree : public line_segtree_base<T> {
    line_segtree(int size) : line_segtree_base<T>(size, {0, plus<T>()}, {{}, plus<line_flag<T>>()},
    [](const T& st, const line_flag<T>& d, int L, int R) { return st + d.eval(R) - d.eval(L); }) {}
    void update(int L, int R, bool inclusive) { line_segtree_base<T>::update(L, R, line_flag<T>(L), inclusive); }
    void update(int i) { line_segtree_base<T>::update(i, line_flag<T>(i)); }
};
