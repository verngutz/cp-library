#include <bits/stdc++.h>
using namespace std;
template <typename T> struct monoid {
    const T identity;
    const function<T(T, T)> combine;
};
