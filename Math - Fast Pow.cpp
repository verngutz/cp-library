using ll = long long;
template <typename T> constexpr void fpow_eq(T& x, ll y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) {
        if(y & 1) {
            identity *= x;
        }
    }
    x = identity;
}
template <typename T> constexpr T fpow(T x, ll y, T identity = 1) {
    T xcopy = x;
    fpow_eq(xcopy, y, identity);
    return xcopy;
}
