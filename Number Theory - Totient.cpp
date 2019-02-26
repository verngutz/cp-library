#include "Number Theory - Factorization O(sqrt n).cpp"
template <typename T>
T phi(T n) {
    T ans = n;
    factorize<T>(n, [](T) {}, [&](T p) { ans -= ans / p; });
    return ans;
}
