#include <bits/stdc++.h>
#include "Math - Fast Pow.cpp"
using namespace std;
template <size_t N> using matrix = vector<bitset<N>>;
template <size_t N> matrix<N> I() {
    matrix<N> I(n, bitset<N>());
    for(size_t i = 0; i < n; i++) {
        I[i].set(i);
    }
    return I;
}
template <size_t N> bitset<N>& operator+=(bitset<N>& u, const bitset<N>& v) { return u ^= v; }
template <size_t N> bitset<N> operator+(const bitset<N>& u, const bitset<N>& v) { return u ^ v; }
template <size_t N, size_t M> bitset<N> operator|(const matrix<N>& A, const bitset<M>& column) {
    bitset<N> ans;
    for(size_t i = 0; i < A.size(); i++) {
        if(column[i]) {
            ans += A[i];
        }
    }
    return ans;
}
template <size_t N, size_t M> matrix<N> operator*(const matrix<N>& A, const matrix<M>& B) { 
    matrix<N> ans(B.size());
    transform(B.begin(), B.end(), ans.begin(), [&](const bitset<M>& column) { return move(A | column); });
    return ans;
}
template <size_t N> matrix<N>& operator^=(matrix<N>& x, long long y) {
    return fpow_eq(x, y, I<N>(x.size()));
}
template <size_t N> matrix<N> operator^(matrix<N> A, long long y) { return move(A ^= y); }
template <size_t N> istream& operator>>(istream& is, bitset<N>& column) { for(int i = 0; i < N; i++) { is >> column[i]; } return is; }
template <size_t N> istream& operator>>(istream& is, matrix<N>& A) { for(bitset<N>& column : A) { is >> column; } return is; }
