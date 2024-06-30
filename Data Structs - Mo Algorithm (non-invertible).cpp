#include <bits/stdc++.h>
using namespace std;
struct query { int i, L, R; };
template <typename T, typename Reset, typename Add1, typename Add2> 
vector<T> mo(int n, vector<query>& queries, const Reset& reset, const Add1& add_and_commit, const Add2& add_range_no_commit) {
    static_assert(is_convertible<decltype(reset), function<void()>>::value, "reset must be void()");
    static_assert(is_convertible<decltype(add_and_commit), function<void(int)>>::value, "add_and_commit must be void(int)");
    static_assert(is_convertible<decltype(add_range_no_commit), function<T(int, int)>>::value, "add_range_no_commit must be T(int, int)");
    vector<T> ans(queries.size());
    int sqrt_n = int(sqrt(n) + 1);
    auto block = [sqrt_n](query& q) { return q.L / sqrt_n; };
    sort(queries.begin(), queries.end(), [&](auto& a, auto& b) {
        return pair(block(a), a.R) < pair(block(b), b.R);
    });
    int max_L = 1, R;
    for(int i = 0; i < queries.size(); i++) {
        query& q = queries[i];
        if(i == 0 or block(q) != block(queries[i - 1])) {
            reset();
            for(int j = i; j < queries.size() and block(queries[j]) == block(q); j++) {
                max_L = max(max_L, queries[j].L);
            }
            R = max_L - 1;
        }
        while(R < q.R) add_and_commit(++R);
        ans[q.i] = add_range_no_commit(q.L, min(q.R, max_L - 1));
    }
    return ans;
}
