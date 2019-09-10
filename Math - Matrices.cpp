#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
using namespace std;
template <typename T, int N, int M> using mat = array<array<T, M>, N>;
template <typename T, int N> using sqmat = mat<T, N, N>;
template <typename T, int N> sqmat<T, N> I() {
    sqmat<T, N> I = {};
    for(int i = 0; i < N; i++) {
        I[i][i] = 1;
    }
    return I;
}
template <typename T, int P, int Q, int R> mat<T, P, R> operator*(const mat<T, P, Q>& A, const mat<T, Q, R>& B) {
    mat<T, P, R> C = {};
    for(int i = 0; i < P; i++) {
        for(int k = 0; k < Q; k++) {
            for(int j = 0; j < R; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
template <typename T, int N> sqmat<T, N> operator*=(sqmat<T, N>& A, sqmat<T, N>& B) { return A = A * B; }
template <typename T, int N> sqmat<T, N> operator^=(sqmat<T, N>& x, long long y) {
    return fpow_eq(x, y, I<T, N>());
}
template <typename T, int N> sqmat<T, N> operator^(sqmat<T, N> x, long long y) { return x ^= y; }
template <typename T, int N> T operator|(const array<T, N>& u, const array<T, N>& v) {
    T ans = 0;
    for(int i = 0; i < N; i++) {
        ans += u[i] * v[i];
    }
    return ans;
}
template <typename T, int N> array<T, N> operator*(const sqmat<T, N>& A, const array<T, N>& x) {
    array<T, N> ans;
    for(int i = 0; i < N; i++) {
        ans[i] = A[i] | x;
    }
    return ans;
}
// NOTE: outer braces required for initialization
// example: matrix<int, 2, 2> m = { {{1, 0}, {0, 1}} };
