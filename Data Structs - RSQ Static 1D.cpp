#include <bits/stdc++.h>
using namespace std;
// #define N 100'000
int n;
long long a[N+1], s[N+1];
void build() {
    a[0] = 0;
    partial_sum(a, a + n, s);
}
long long query(int L, int R=n) {
    return s[R] - s[L-1];
}
