#include <bits/stdc++.h>
#include "Combinatorics - K-Simplex Numbers.cpp"
// Σ a0 + r*i for i in [0, n)
template <typename Out = mint, typename In = int> Out arith0(Out a0, Out r, In n) {
    return a0 * n + r * sk_simplex<Out, In>(n - 1, 1);
}
// Σ a0 + r*i for i in [1, n]
template <typename Out = mint, typename In = int> Out arith1(Out a0, Out r, In n) {
    return a0 * n + r * sk_simplex<Out, In>(n, 1);
}
// Σ a0 + b0*i + arith1(i)*c for i in [0, n)
template <typename Out = mint, typename In = int> Out quadratic0(Out a0, Out b0, Out c, In n) {
    return a0 * n + b0 * sk_simplex<Out, In>(n - 1, 1) + c * sk_simplex<Out, In>(n - 1, 2);
}
// Σ a0 + b0*i + arith1(i)*c for i in [1, n]
template <typename Out = mint, typename In = int> Out quadratic1(Out a0, Out b0, Out c, In n) {
    return a0 * n + b0 * sk_simplex<Out, In>(n, 1) + c * sk_simplex<Out, In>(n, 2);
}
