#include <bits/stdc++.h>
#include "Math - Matrices (bitset columns).cpp"
using namespace std;
template <size_t N> tuple<matrix<N>, matrix<N>, matrix<N>> LUP_factorize(matrix<N>& A) {
    matrix<T> P = I<T>(A.size()), U = I<T>(A.size());
    for(size_t i = 0; i < A.size(); i++) {
        auto it = find_if(A.begin() + i, A.end(), [&](const bitset<N>& column) { return column[i]; });
        if(it == A.end()) {
            throw invalid_argument("matrix is singular");
        }
        swap(A[i], *it);
        swap(P[i], P[it - A.begin()]);
        for(size_t j = 0; j < i; j++) {
            swap(U[i][j], U[it - A.begin()][j]);
        }
        for(size_t j = i + 1; j < A.size(); j++) {
            if(A[j][i]) {
                U[j][i] ^= 1;
                A[j] += A[i];
            }
        }
    }
    return {move(A), move(U), move(P)};
}
template <size_t N> matrix<N> operator~(matrix<N> A) {
    auto [L, U, P] = LUP_factorize(A);
    matrix<N> inverse = I<N>(P.size());
    auto back_substitute = [](const matrix<N>& A, int direction, bitset<N> y) {
        bitset<N> ans;
        for(int i = direction == 1 ? 0 : A.size() - 1; 0 <= i and i < A.size(); i += direction) {
            if(y[i]) {
                ans[i] = 1;
                y += A[i];
            }
        }
        return ans;
    };
    transform(inverse.begin(), inverse.end(), inverse.begin(), [&](const bitset<N>& column) {
        return move(back_substitute(U, -1, back_substitute(L, 1, column)));
    });
    return move(inverse *= P);
}
template <size_t N, size_t M> bitset<N> solve(const matrix<N>& A, const bitset<M>& y) {
    return move((~A) | y);
}
