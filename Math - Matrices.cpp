#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
using namespace std;
template <typename T> vector<T>& operator+=(vector<T>& u, const vector<T>& v) {
    transform(u.begin(), u.end(), v.begin(), u.begin(), plus<T>());
    return u;
}
template <typename T> vector<T> operator+(vector<T> u, const vector<T>& v) { return move(u += v); }
template <typename T> vector<T>& operator-=(vector<T>& u, const vector<T>& v) {
    transform(u.begin(), u.end(), v.begin(), u.begin(), minus<T>());
    return u;
}
template <typename T> vector<T> operator-(vector<T> u, const vector<T>& v) { return move(u -= v); }
template <typename T> vector<T>& operator*=(vector<T>& v, const T& scalar) {
    transform(v.begin(), v.end(), v.begin(), [&](const T& component) { return move(component * scalar); });
    return v;
}
template <typename T> vector<T> operator*(vector<T> v, const T& scalar) { return move(v *= scalar); }
template <typename T> vector<T> operator*(const T& scalar, vector<T> v) { return move(v *= scalar); }
template <typename T> vector<T>& operator/=(vector<T>& v, const T& scalar) {
    transform(v.begin(), v.end(), v.begin(), [&](const T& component) { return move(component / scalar); });
    return v;
}
template <typename T> vector<T> operator/(vector<T> v, const T& scalar) { return move(v /= scalar); }
template <typename T> T operator|(const vector<T>& u, const vector<T>& v) {
    return inner_product(u.begin(), u.end(), v.begin(), 0);
}
template <typename T> using matrix = vector<vector<T>>;
template <typename T> matrix<T> I(size_t n) {
    matrix<T> I(n, vector<T>(n));
    for(size_t i = 0; i < n; i++) I[i][i] = T(1);
    return move(I);
}
template <typename T> matrix<T>& operator+=(matrix<T>& A, const matrix<T>& B) {
    transform(A.begin(), A.end(), B.begin(), A.begin(), plus<vector<T>>());
    return A;
}
template <typename T> matrix<T> operator+(matrix<T> A, const matrix<T>& B) { return move(A += B); }
template <typename T> matrix<T>& operator-=(matrix<T>& A, const matrix<T>& B) {
    transform(A.begin(), A.end(), B.begin(), A.begin(), minus<vector<T>>());
    return A;
}
template <typename T> matrix<T> operator-(matrix<T> A, const matrix<T>& B) { return move(A -= B); }
template <typename T> matrix<T>& operator*=(matrix<T>& A, const T& scalar) {
    transform(A.begin(), A.end(), A.begin(), [&](const vector<T>& column) { return move(column * scalar); });
    return A;
}
template <typename T> matrix<T>& operator*=(const T& scalar, matrix<T>& A) { return A *= scalar; }
template <typename T> matrix<T> operator*(matrix<T> A, const T& scalar) { return move(A *= scalar); }
template <typename T> matrix<T> operator*(const T& scalar, matrix<T> A) { return move(A *= scalar); }
template <typename T> matrix<T>& operator/=(matrix<T>& A, const T& scalar) {
    transform(A.begin(), A.end(), A.begin(), [&](const vector<T>& column) { return move(column / scalar); });
    return A;
}
template <typename T> matrix<T>& operator/=(const T& scalar, matrix<T>& A) { return A /= scalar; }
template <typename T> matrix<T> operator/(matrix<T> A, const T& scalar) { return move(A /= scalar); }
template <typename T> matrix<T> operator/(const T& scalar, matrix<T> A) { return move(A /= scalar); }
template <typename T> vector<T> operator|(const matrix<T>& A, const vector<T>& column) {
    return inner_product(A.begin(), A.end(), column.begin(), vector<T>(A[0].size()));
}
template <typename T> matrix<T>& operator*=(matrix<T>& B, const matrix<T>& A) {
    transform(B.begin(), B.end(), B.begin(), [&](const vector<T>& column) { return move(A | column); });
    return B;
}
template <typename T> matrix<T> operator*(const matrix<T>& A, matrix<T> B) { return move(B *= A); }
template <typename T> matrix<T>& operator^=(matrix<T>& x, long long y) {
    return fpow_eq(x, y, I<T>(x.size()));
}
template <typename T> matrix<T> operator^(matrix<T> A, long long y) { return move(A ^= y); }
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
        return move(ans);
    };
    transform(inverse.begin(), inverse.end(), inverse.begin(), [&](const vector<T>& column) {
        return move(back_substitute(U, -1, back_substitute(L, 1, column))); 
    });
    return move(inverse *= transpose(P));
}
template <typename T> vector<T> solve(const matrix<T>& A, const vector<T>& y) {
    return move((~A) | y);
}
template <typename T> istream& operator>>(istream& is, matrix<T>& A) { for(vector<T>& column : A) { is >> column; } return is; }
