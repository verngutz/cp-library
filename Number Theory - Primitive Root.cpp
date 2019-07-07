#include "Number Theory - Totient.cpp"
#include "Math - Modular Arithmetic.cpp"
template <int N> constexpr modint<N, phi(N)> primitive_root() {
    for(modint<N, phi(N)> a = 2; a <= N - 1; a++) {
        bool is_primitive_root = true;
        factorize<ll>(phi(N), [](ll) {}, [&](ll p) {
            is_primitive_root &= (a ^ (phi(N) / p)) != 1;
        });
        if(is_primitive_root) {
            return a;
        }
    }
    return 0;
}
