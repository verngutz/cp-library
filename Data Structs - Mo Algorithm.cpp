#include <bits/stdc++.h>
#include "callable.hpp/callable.hpp"
using namespace std;
// const int N = 30'000;
// const int SQRTN = int(sqrt(N) + 1);
struct query { int L, R, i; };
int block(int i) {
    return i / SQRTN;
}
template <typename T, typename AddFunction, typename RemoveFunction, typename AnswerFunction>
vector<T> mo(vector<query>& queries, AddFunction add, RemoveFunction remove, AnswerFunction answer) {
#ifdef DEBUG
    using add_actual_type = typename callable_traits<AddFunction>::function_type;
    using add_expected_type = typename callable_traits<void(int)>::function_type;
    static_assert(is_same<add_actual_type, add_expected_type>::value, "mo 'add' must be void(int)");
    using remove_actual_type = typename callable_traits<RemoveFunction>::function_type;
    using remove_expected_type = typename callable_traits<void(int)>::function_type;
    static_assert(is_same<remove_actual_type, remove_expected_type>::value, "mo 'remove' must be void(int)");
    using answer_actual_type = typename callable_traits<AnswerFunction>::function_type;
    using answer_expected_type = typename callable_traits<T(int, int)>::function_type;
    static_assert(is_same<answer_actual_type, answer_expected_type>::value, "mo 'answer' must be T(int, int)");
#endif
    vector<T> ans(queries.size());
    sort(queries.begin(), queries.end(), [](auto& a, auto& b) {
        return block(a.L) == block(b.L) ? a.R < b.R : block(a.L) < block(b.L);
    });
    int L = 1;
    int R = 0;
    for(const query& q : queries) {
        while(R < q.R) add(++R);
        while(R > q.R) remove(R--);
        while(L < q.L) remove(L++);
        while(L > q.L) add(--L);
        ans[q.i] = answer(q.L, q.R);
    }
    return ans;
}
