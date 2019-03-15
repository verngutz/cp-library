#include <bits/stdc++.h>
using namespace std;
template <typename Iter, typename T> int gt(Iter L, Iter R, T v) { return upper_bound(L, R, v) - L; }
template <typename Iter, typename T> int ge(Iter L, Iter R, T v) { return lower_bound(L, R, v) - L; }
template <typename Iter, typename T> int lt(Iter L, Iter R, T v) { return lower_bound(L, R, v) - L - 1; }
template <typename Iter, typename T> int le(Iter L, Iter R, T v) { return upper_bound(L, R, v) - L - 1; }
template <typename Bst, typename T> typename Bst::const_iterator gt(const Bst& bst, T v) { return bst.upper_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator ge(const Bst& bst, T v) { return bst.lower_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator lt(const Bst& bst, T v) { return bst.lower_bound(v) == bst.begin() ? bst.end() : --bst.lower_bound(v); }
template <typename Bst, typename T> typename Bst::const_iterator le(const Bst& bst, T v) { return bst.upper_bound(v) == bst.begin() ? bst.end() : --bst.upper_bound(v); }
