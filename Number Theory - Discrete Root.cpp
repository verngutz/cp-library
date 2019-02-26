#include "Number Theory - Primitive Root.cpp"
#include "Number Theory - Discrete Logarithm.cpp"
// find one x (mod c) such that x^a = b (mod c), or ath root of b = x (mod c)
vector<int> root(int a, int b, int c) {
    modint g = primitive_root(c);
    set_M(c);
    auto y = dlog((g ^ a).val, b, c);
    set_M(c);
    return y.empty() ? vector<int>() : vector<int>({(g ^ y[0]).val});
}
