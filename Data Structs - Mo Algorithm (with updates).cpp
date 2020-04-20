#include <bits/stdc++.h>
using namespace std;
struct query { int i, L, R; };
struct update { int i, p, x; };
template <typename signature> using f = const function<signature>&;
template <typename T> vector<T> mo(int n, const vector<query>& queries, const vector<update>& updates,
f<void()> reset, f<void(int)> add, f<void(int)> remove, f<T()> answer, f<void(const update&)> do_update) {
    vector<T> ans(queries.size());
    int cbrt_n = int(cbrt(n) + 1);
    sort(queries.begin(), queries.end(), [&](auto& a, auto& b) {
        return tuple(a.L / cbrt_n, a.R / cbrt_n, a.i) < tuple(b.L / cbrt_n, b.R / cbrt_n, b.i);
    });
    int L, R, previ, uptr;
    auto range_guarded = [&](function<void(int)> f) {
        return [&](int i) { if(L <= i and i <= R) f(i); };
    };
    auto guarded_add = range_guarded(add);
    auto guarded_remove = range_guarded(remove);
    auto reset_and_init_pointers = [&]() { reset(), uptr = 0, L = 0, R = -1, previ = -1; };
    reset_and_init_pointers();
    for(const query& q : queries) {
        if(q.i < previ) reset_and_init_pointers();
        while(R < q.R) guarded_add(++R);
        while(R > q.R) guarded_remove(R--);
        while(L < q.L) guarded_remove(L++);
        while(L > q.L) guarded_add(--L);
        while(uptr < updates.size() and updates[uptr].i < q.i) {
            remove(updates[uptr].i);
            do_update(updates[uptr]);
            add(updates[uptr].i);
            uptr++;
        }
        ans[q.i] = answer();
        previ = q.i;
    }
    return ans;
}
