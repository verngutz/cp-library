#include <bits/stdc++.h>
#include "Math - Matrices.cpp"
template <typename T> matrix<T>& transpose(matrix<T>& A) {
    int num_cols = A.size(), num_rows = A[0].size(), mini = min(num_cols, num_rows), maxi = max(num_cols, num_rows);
    for_each(A.begin(), A.begin() + mini, [&](vector<T>& column) { column.resize(maxi); });
    A.resize(maxi, vector<T>(mini));
    for(int i = 0; i < num_cols; i++) 
        for(int j = i + 1; j < num_rows; j++) 
            swap(A[i][j], A[j][i]);
    A.resize(num_rows);
    for_each(A.begin(), A.end(), [&](vector<T>& column) { column.resize(num_cols); });
    return A;
}
template <typename T> matrix<T> transposed(matrix<T> A) { return move(transpose(A)); }
template <typename T> tuple<matrix<T>, matrix<T>, matrix<T>> LUP_factorize(matrix<T>& A) {
    matrix<T> P = I<T>(A.size()), U = I<T>(A.size());
    for(size_t i = 0; i < A.size(); i++) {
        auto it = find_if_not(A.begin() + i, A.end(), [&](const vector<T>& column) { return column[i] == T(0); });
        if(it == A.end()) {
            throw invalid_argument("matrix is singular");
        }
        swap(A[i], *it);
        swap(P[i], P[it - A.begin()]);
        for(size_t j = 0; j < i; j++) {
            swap(U[i][j], U[it - A.begin()][j]);
        }
        U[i] *= A[i][i];
        A[i] /= A[i][i];
        for(size_t j = i + 1; j < A.size(); j++) {
            U[j][i] += A[j][i];
            A[j] -= A[j][i] * A[i];
        }
    }
    return {move(A), move(U), move(transpose(P))};
}
template <typename T> matrix<T> operator~(matrix<T> A) {
    auto [L, U, P] = LUP_factorize(A);
    matrix<T> inverse = I<T>(P.size());
    auto back_substitute = [](const matrix<T>& A, int direction, vector<T> y) {
        vector<T> ans(A.size());
        for(int i = direction == 1 ? 0 : A.size() - 1; 0 <= i and i < A.size(); i += direction) {
            y += (ans[i] = y[i]) / A[i][i] * A[i];
        }
        return ans;
    };
    transform(inverse.begin(), inverse.end(), inverse.begin(), [&](const vector<T>& column) {
        return move(back_substitute(U, -1, back_substitute(L, 1, column))); 
    });
    return move(inverse *= transpose(P));
}
template <typename T> vector<T> solve(const matrix<T>& A, const vector<T>& y) {
    return move((~A) | y);
}
