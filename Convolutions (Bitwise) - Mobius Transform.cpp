#include <bits/stdc++.h>
#include "Convolutions (Bitwise) - Zeta Transform.cpp"
using namespace std;
template <typename T> vector<T>& sigma(vector<T>& a) {
    for(int i = 0; i < a.size(); i++) {
        if(__builtin_popcount(i) % 2) {
            a[i] = -a[i];
        }
    }
    return a;
}
template <typename T> vector<T>& mu(vector<T>& a) {
    return sigma(zeta(sigma(a)));
}
