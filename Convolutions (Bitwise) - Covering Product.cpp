#include <bits/stdc++.h>
#include "Convolutions (Bitwise) - Mobius Transform.cpp"
using namespace std;
template <typename T> vector<T>& operator*=(vector<T>& a, vector<T>& b) {
    zeta(a);
    if(addressof(a) != addressof(b)) zeta(b);
    assert(a.size() == b.size());
    transform(a.begin(), a.end(), b.begin(), a.begin(), multiplies<T>());
    if(addressof(a) != addressof(b)) mu(b);
    return mu(a);
}
template <typename T> vector<T> operator*(vector<T> a, vector<T>& b) { return a *= b; }
