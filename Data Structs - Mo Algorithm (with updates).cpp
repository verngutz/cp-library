#include <bits/stdc++.h>
using namespace std;
struct query { int i, L, R; };
struct update { int i, p, x; };
template <typename T, typename Reset, typename Add, typename Remove, typename Answer, typename Update> 
vector<T> mo(int n, vector<query>& queries, const vector<update>& updates,
const Reset& reset, const Add& add, const Remove& remove, const Answer& answer, const Update& do_update) {
    static_assert(is_convertible<decltype(reset), function<void()>>::value);
    static_assert(is_convertible<decltype(add), function<void(int)>>::value);
    static_assert(is_convertible<decltype(remove), function<void(int)>>::value);
    static_assert(is_convertible<decltype(answer), function<T()>>::value);
    static_assert(is_convertible<decltype(do_update), function<void(const update&)>>::value);
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
