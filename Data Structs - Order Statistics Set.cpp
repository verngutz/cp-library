#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// usage:
// ordered_set<int> s;
// s.insert(key);
// s.find_by_order(ordinality); returns iterator to key
// s.order_of_key(key); returns ordinality
// s.erase(key);
// do ordered_set<pair<Key, Id>> for multiset
