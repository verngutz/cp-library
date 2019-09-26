#include <bits/stdc++.h>
using namespace std;
template <typename T> struct grid : public vector<vector<T>> {
    int n, m;
    grid(int n, int m) : vector<vector<T>>(n, vector<T>(m)), n(n), m(m) {}
    grid(int n, int m, T zero) : vector<vector<T>>(n, vector<T>(m, zero)), n(n), m(m) {}
    grid(const grid& a) : vector<vector<T>>(a), n(a.n), m(a.m) {}
};
