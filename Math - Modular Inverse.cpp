#include "Number Theory - Totient.cpp"
#include "Math - Fast Pow.cpp"
using ll = long long;
template <typename T> T minv(T x, ll m) {
    return fpow(x, phi(m) - 1);
}
