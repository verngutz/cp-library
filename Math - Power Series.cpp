using ll = long long;
template <typename T> T& power_series_eq(T& x, ll num_terms, T plus_identity = 0, T times_identity = 1) {
    T& sum = plus_identity;
    T& terms = times_identity;
    T prev_terms = plus_identity;
    for(; num_terms > 0; num_terms >>= 1) {
        if(num_terms & 1) {
            sum *= x;
            sum += terms;
        }
        prev_terms = terms;
        terms *= x;
        terms += prev_terms;
        x *= x;
    }
    return x = sum;
}
template <typename T> T power_series(T x, ll num_terms, T plus_identity = 0, T times_identity = 1) {
    return move(power_series_eq(x, num_terms, move(plus_identity), move(times_identity)));
}
