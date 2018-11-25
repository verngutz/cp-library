#include <bits/stdc++.h>
using namespace std;
struct query { int L, R, i; };
template <typename signature> using f = const function<signature>&;
template <typename T>
vector<T> mo(const vector<query>& queries, f<void(int)> add, f<void(int)> remove, f<void(int, int)> answer) {
    vector<T> ans(queries.size());
    int sqrt_q = int(sqrt(queries.size()) + 1);
    sort(queries.begin(), queries.end(), [&](auto& a, auto& b) {
        return pair(a.L / sqrt_q, a.R) < pair(b.L / sqrt_q, b.R);
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
