#include "Combinatorics - Combinations.cpp"
template <typename T = mint> T B(int n) {
    static vector<T> b = {1};
    while(b.size() <= n) {
        int N = b.size();
        T next = 1;
        for(int k = 0; k < N; k++) {
            next -= C(N, k) * b[k] / (N - k + 1);
        }
        b.push_back(next);
    }
    return b[n];
}
template <typename T = mint> T sum_of_powers(T n, int p) {
    T ans = 0;
    for(int j = 0; j <= p; j++) {
        ans += C(p + 1, j) * B(j) * (n ^ (p + 1 - j));
    }
    return ans / (p + 1);
}
