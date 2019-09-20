#include <bits/stdc++.h>
#include "Convolutions (Bitwise) - Zeta Transform.cpp"
using namespace std;
template <typename T> vector<T>& sigma(vector<T>& a) {
    for(int i = 0; i < a.size(); i++) {
        a[i] *= -2 * (__builtin_popcount(i) % 2) + 1;
    }
    return a;
}
template <typename T> vector<T>& mu(vector<T>& a) {
    return sigma(zeta(sigma(a)));
}
