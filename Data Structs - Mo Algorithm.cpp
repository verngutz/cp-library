#include <bits/stdc++.h>
using namespace std;
struct query { int i, L, R; };
template <typename T, typename Add, typename Remove, typename Answer>
vector<T> mo(int n, vector<query>& queries, const Add& add, const Remove& remove, const Answer& answer) {
    static_assert(is_convertible<decltype(add), function<void(int)>>::value, "add must be void(int)");
    static_assert(is_convertible<decltype(remove), function<void(int)>>::value, "remove must be void(int)");
    static_assert(is_convertible<decltype(answer), function<T(int, int)>>::value, "answer must be T(int, int)");
    vector<T> ans(queries.size());
    int sqrt_n = int(sqrt(n) + 1);
    sort(queries.begin(), queries.end(), [&](auto& a, auto& b) {
        return pair(a.L / sqrt_n, a.R) < pair(b.L / sqrt_n, b.R);
    });
    int L = 1, R = 0;
    for(const query& q : queries) {
        while(R < q.R) add(++R);
        while(R > q.R) remove(R--);
        while(L < q.L) remove(L++);
        while(L > q.L) add(--L);
        ans[q.i] = answer(q.L, q.R);
    }
    return ans;
}
