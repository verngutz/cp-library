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
    return I;
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
    if(addressof(B) == addressof(A)) return B = (A * B);
    transform(B.begin(), B.end(), B.begin(), [&](const vector<T>& column) { return move(A | column); });
    return B;
}
template <typename T> matrix<T> operator*(const matrix<T>& A, matrix<T> B) { return move(B *= A); }
template <typename T> matrix<T>& operator^=(matrix<T>& x, long long y) {
    return fpow_eq(x, y, I<T>(x.size()));
}
template <typename T> matrix<T> operator^(matrix<T> A, long long y) { return move(A ^= y); }
template <typename T> istream& operator>>(istream& is, matrix<T>& A) { for(vector<T>& column : A) { is >> column; } return is; }
