using ll = long long;
template <typename T>
T fpow(T x, ll y) {
    T ans = 1;
    for(; y > 0; x *= x, y >>= 1) {
        if(y & 1) {
            ans *= x;
        }
    }
    return ans;
}
