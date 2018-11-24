#include "Math - Modular Arithmetic.cpp"
#include "Combinatorics - Combinations.cpp"
modint B(int n) {
    static vector<modint> b = {1};
    while(b.size() <= n) {
        int N = b.size();
        modint next = 1;
        for(int k = 0; k < N; k++) {
            next -= C(N, k) * b[k] / (N - k + 1);
        }
        b.push_back(next);
    }
    return b[n];
}
modint sum_of_powers(modint n, int p) {
    modint ans = 0;
    for(int j = 0; j <= p; j++) {
        ans += C(p + 1, j) * B(j) * (n ^ (p + 1 - j));
    }
    return ans / (p + 1);
}
