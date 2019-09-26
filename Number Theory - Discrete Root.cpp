#include "Number Theory - Primitive Root.cpp"
#include "Number Theory - Discrete Logarithm.cpp"
// find one x (mod M) such that x^a = b (mod M), or ath root of b = x (mod M)
template <int M> vector<int> root(int a, int b) {
    modint<M> g = primitive_root<M>();
    vector<ll> y = dlog((g ^ a).val, b, M, true);
    return y.empty() ? vector<int>() : vector<int>({(g ^ y[0]).val});
}
