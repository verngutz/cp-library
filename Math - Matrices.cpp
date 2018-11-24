#include <bits/stdc++.h>
using namespace std;
template <typename T, int P, int Q, int R>
array<array<T, R>, P> matrix_multiply(const array<array<T, Q>, P>& A, const array<array<T, R>, Q>& B) {
    array<array<T, R>, P> C = {};
    for(int i = 0; i < P; i++) {
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < Q; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
template <typename T, int N>
array<array<T, N>, N> matrix_identity() {
    array<array<T, N>, N> I = {};
    for(int i = 0; i < N; i++) {
        I[i][i] = 1;
    }
    return I;
}
template <typename T, int N>
array<array<T, N>, N> matrix_power(const array<array<T, N>, N>& x, long long y) {
    if(y == 0) {
        return matrix_identity<T, N>();
    } else {
        auto z = matrix_power<T, N>(x, y / 2);
        auto sq = matrix_multiply<T, N, N, N>(z, z);
        return y % 2 ? matrix_multiply<T, N, N, N>(sq, x) : sq;
    }
}
template <typename T, int N>
T dot_product(const array<T, N>& u, const array<T, N>& v) {
    T ans = 0;
    for(int i = 0; i < N; i++) {
        ans += u[i] * v[i];
    }
    return ans;
}
template <typename T, int N>
array<T, N> matrix_transform(const array<array<T, N>, N>& A, const array<T, N>& x) {
    array<T, N> ans;
    for(int i = 0; i < N; i++) {
        ans[i] = dot_product<T, N>(A[i], x);
    }
    return ans;
}
