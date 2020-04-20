#ifndef __TOTIENT_INCLUDED_
#define __TOTIENT_INCLUDED_
#include "Number Theory - Factorization O(sqrt n).cpp"
template <typename T> constexpr T phi(T n) {
    T ans = n;
    factorize<T>(n, [](T) {}, [&](T p) { ans -= ans / p; });
    return ans;
}
#endif
