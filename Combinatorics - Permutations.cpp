#include "Math - Modular Arithmetic.cpp"
template <typename T = mint> T fact(int n) {
    static vector<T> fac = {1};
    while(fac.size() <= n) {
        fac.push_back(fac.back() * int(fac.size()));
    }
    return fac[n];
}
template <typename T = mint> T fact_inv(int n) {
    static vector<T> inv_fac = {1};
    while(inv_fac.size() <= n) {
        inv_fac.push_back(inv_fac.back() / int(inv_fac.size()));
    }
    return inv_fac[n];
}
