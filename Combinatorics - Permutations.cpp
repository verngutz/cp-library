#include "Math - Modular Arithmetic.cpp"
template <typename T = mint> T fact(int n) {
    static vector<T> fac = {1};
    fac.reserve(n + 1);
    while(fac.size() <= n) {
        fac.push_back(fac.back() * int(fac.size()));
    }
    return fac[n];
}
template <typename T = mint> T fact_inv(int n) {
    static vector<T> inv_fac;
    if(inv_fac.size() <= n) {
        int old_size = inv_fac.size();
        inv_fac.resize(n + 1);
        inv_fac[n] = ~fact(n);
        for(int i = n - 1; i >= old_size; i--) {
            inv_fac[i] = inv_fac[i + 1] * (i + 1);
        }
    }
    return inv_fac[n];
}
