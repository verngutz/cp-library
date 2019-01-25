#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
using namespace std;
template <typename T, size_t N, size_t M> using matrix = array<array<T, M>, N>;
template <typename T, size_t N> using sq_matrix = matrix<T, N, N>;
template <typename T, size_t P, size_t Q, size_t R>
matrix<T, P, R> operator*(const matrix<T, P, Q>& A, const matrix<T, Q, R>& B) {
    matrix<T, P, R> C = {};
    for(size_t i = 0; i < P; i++) {
        for(size_t j = 0; j < R; j++) {
            for(size_t k = 0; k < Q; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
template <typename T, size_t N>
sq_matrix<T, N> operator*=(sq_matrix<T, N>& A, sq_matrix<T, N>& B) {
    return A = A * B;
}
template <typename T, size_t N>
sq_matrix<T, N> I() {
    sq_matrix<T, N> I = {};
    for(size_t i = 0; i < N; i++) {
        I[i][i] = 1;
    }
    return I;
}
template <typename T, size_t N>
sq_matrix<T, N> operator^=(sq_matrix<T, N>& x, long long y) {
    fpow_eq(x, y, I<T, N>());
    return x;
}
template <typename T, size_t N>
sq_matrix<T, N> operator^(const sq_matrix<T, N>& x, long long y) {
    return fpow(x, y, I<T, N>());
}
template <typename T, size_t N>
T operator|(const array<T, N>& u, const array<T, N>& v) {
    T ans = 0;
    for(size_t i = 0; i < N; i++) {
        ans += u[i] * v[i];
    }
    return ans;
}
template <typename T, size_t N>
array<T, N> operator*(const sq_matrix<T, N>& A, const array<T, N>& x) {
    array<T, N> ans;
    for(size_t i = 0; i < N; i++) {
        ans[i] = A[i] | x;
    }
    return ans;
}
// NOTE: outer braces required for initialization
// example: matrix<int, 2, 2> m = { {{1, 0}, {0, 1}} };
