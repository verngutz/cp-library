#include <bits/stdc++.h>
// const int N = 100'000;
// const int Q = 100'000;
// const int QBRTQ = int(cbrt(Q) + 1);
using namespace std;
int n;
int origa[N], a[N];
struct query { int L, R, i; };
struct update { int p, x, i; };
int block(int i) {
    return i / QBRTQ;
}
template<typename T>
vector<T> mo(vector<query>& queries, vector<update>& updates,
             function<void(int)> add, function<void(int)> remove,
             function<T()> get_ans, function<void(update&)> do_update) {
    vector<T> ans();
    sort(queries.begin(), queries.end(), [](auto& a, auto& b) {
        if(block(a.L) == block(b.L)) {
            if(block(a.R) == block(b.R)) return a.i < b.i;
            else return block(a.R) < block(b.R);
        } else return block(a.L) < block(b.L);
    });
    int L, R, previ, uptr;
    auto range_guarded = [&](function<void(int)> f) {
        return [&](int i) { if(L <= i and i <= R) f(i); };
    };
    auto guarded_add = range_guarded(add);
    auto guarded_remove = range_guarded(remove);
    auto reset = [&]() {
        for(int i = 0; i < n; i++) {
            a[i] = origa[i];
        }
        uptr = 0;
        L = 0;
        R = -1;
        previ = -1;
    };
    reset();
    for(const query& q : queries) {
        if(q.i < previ) reset();
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
        ans[q.i] = get_ans();
        previ = q.i;
    }
    return ans;
}
