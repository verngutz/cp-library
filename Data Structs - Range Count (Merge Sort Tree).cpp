#include <bits/stdc++.h>
using namespace std;
template <typename T> struct mergesort_tree {
    inline static vector<T> values = vector<T>(), tmp = vector<T>();
    int s, e;
    vector<int> L_cascade, R_cascade;
    mergesort_tree *l, *r;
    void build() {
        L_cascade.resize(e - s + 1);
        R_cascade.resize(e - s + 1);
        if(e - s == 1) {
            l = r = nullptr;
        } else {
            int m = midpoint(s, e);
            l = new mergesort_tree(s, m);
            r = new mergesort_tree(m, e);
            merge(values.begin() + s, values.begin() + m, values.begin() + m, values.begin() + e, tmp.begin() + s);
            for(int i = 0, l_ptr = 0, r_ptr = 0; i <= e - s; i++) {
                L_cascade[i] = l_ptr, R_cascade[i] = r_ptr;
                (s + l_ptr < m and tmp[s + i] == values[s + l_ptr] ? l_ptr : r_ptr)++;
            }
            copy(tmp.begin() + s, tmp.begin() + e, values.begin() + s);
        }
    }
    mergesort_tree(const vector<T>& a): s(0), e(ssize(a)) {
        values.resize(ssize(a));
        copy(a.begin(), a.end(), values.begin());
        tmp.resize(ssize(a));
        build();
    }
    ~mergesort_tree() {
        delete l;
        delete r;
    }
    int count_leq(int L, int R, bool inclusive, const T& val) {
        int fraction = ranges::upper_bound(values, val) - values.begin();
        return count_leq(L, R + inclusive, fraction);
    }
private:
    mergesort_tree(int s, int e): s(s), e(e) {
        build();
    }
    int count_leq(int L, int R, int fraction) {
        if(L <= s and e <= R) {
            return fraction;
        } else if(R <= s or e <= L) {
            return 0;
        } else {
            return l->count_leq(L, R, L_cascade[fraction]) + r->count_leq(L, R, R_cascade[fraction]);
        }
    }
};
