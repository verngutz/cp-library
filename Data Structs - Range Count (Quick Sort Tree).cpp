template <typename T, T MIN_VAL, T MAX_VAL> struct quicksort_tree {
    const vector<T>& a;
    inline static vector<T> indices = vector<T>(), tmp = vector<T>();
    T min_val, max_val;
    quicksort_tree *l, *r;
    vector<int> L_cascade, R_cascade;
    void build(int s, int e) {
        L_cascade.resize(e - s + 1);
        R_cascade.resize(e - s + 1);
        while(true) {
            if(max_val - min_val == 1) {
                l = r = nullptr;
                break;
            } else {
                T mid_val = midpoint(min_val, max_val);
                auto lt_mid = [&](int i) { return a[i] < mid_val; };
                if(all_of(indices.begin() + s, indices.begin() + e, lt_mid)) {
                    max_val = mid_val;
                } else if(not any_of(indices.begin() + s, indices.begin() + e, lt_mid)) {
                    min_val = mid_val;
                } else {
                    copy(indices.begin() + s, indices.begin() + e, tmp.begin() + s);
                    auto m = stable_partition(indices.begin() + s, indices.begin() + e, lt_mid) - indices.begin();
                    for(int i = 0, l_ptr = 0, r_ptr = 0; i <= e - s; i++) {
                        L_cascade[i] = l_ptr, R_cascade[i] = r_ptr;
                        (s + l_ptr < m and tmp[s + i] == indices[s + l_ptr] ? l_ptr : r_ptr)++;
                    }
                    l = new quicksort_tree(a, min_val, mid_val, s, m);
                    r = new quicksort_tree(a, mid_val, max_val, m, e);
                    break;
                }
            }
        }
    }
    quicksort_tree(const vector<T>& a): a(a), min_val(MIN_VAL), max_val(MAX_VAL + 1) {
        indices.resize(ssize(a));
        ranges::iota(indices, 0);
        tmp.resize(ssize(a));
        build(0, ssize(a));
    }
    ~quicksort_tree() {
        delete l;
        delete r;
    }
    int count_leq(int L, int R, bool inclusive, const T& val) {
        return count_leq(L, R + inclusive, val);
    }
    T kth_smallest(int L, int R, bool inclusive, int k) {
        return kth_smallest(L, R + inclusive, k);
    }
private:
    quicksort_tree(const vector<T>& a, T min_val, T max_val, int s, int e): a(a), min_val(min_val), max_val(max_val) {
        build(s, e);
    }
    int count_leq(int L, int R, const T& val) {
        if(val >= max_val - 1) {
            return R - L;
        } else if(val < min_val) {
            return 0;
        } else {
            return l->count_leq(L_cascade[L], L_cascade[R], val) + r->count_leq(R_cascade[L], R_cascade[R], val);
        }
    }
    T kth_smallest(int L, int R, int k) {
        if(max_val - min_val == 1) {
            return min_val;
        } else {
            int k_right = k - l->count_leq(L_cascade[L], L_cascade[R], l->max_val);
            if(k_right >= 0) {
                return r->kth_smallest(R_cascade[L], R_cascade[R], k_right);
            } else {
                return l->kth_smallest(L_cascade[L], L_cascade[R], k);
            }
        }
    }
};
