#include <bits/stdc++.h>
using namespace std;
struct query { int L, R, i; };
struct update { int p, x, i; };
template <typename signature> using f = const function<signature>&;
template <typename T> vector<T> mo(const vector<query>& queries, const vector<update>& updates,
f<void()> reset, f<void(int)> add, f<void(int)> remove, f<T()> answer, f<void(const update&)> do_update) {
    vector<T> ans(queries.size());
    int cbrt_q = int(cbrt(queries.size()) + 1);
    sort(queries.begin(), queries.end(), [&](auto& a, auto& b) {
        return tuple(a.L / cbrt_q, a.R / cbrt_q, a.i) < tuple(b.L / cbrt_q, b.R / cbrt_q, b.i);
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
