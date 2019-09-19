#ifndef __FASTPOW_INCLUDED_
#define __FASTPOW_INCLUDED_
using ll = long long;
template <typename T> constexpr T fpow_eq(T& x, ll y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) if(y & 1) identity *= x;
    return x = identity;
}
template <typename T> constexpr T fpow(T x, ll y, T identity = 1) { return fpow_eq(x, y, identity); }
#endif
