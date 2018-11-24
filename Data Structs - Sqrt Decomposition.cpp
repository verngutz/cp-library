#include <bits/stdc++.h>
#define N 200'000
#define SQRTN int(sqrt(N) + 1)
using namespace std;
int n, q;
long long a[N];
long long bin[SQRTN];
long long delta[SQRTN];
bool is_lazy[SQRTN];
int block(int i) {
    return i / SQRTN;
}
int block_start(int b) {
    return b * SQRTN;
}
int block_end(int b) {
    return min(block_start(b + 1) - 1, n - 1);
}
void build(int b) {
    bin[b] = 0;
    for(int i = block_start(b); i <= block_end(b); i++) {
        bin[b] += a[i];
    }
}
void unlazy(int b) {
    if(is_lazy[b]) {
        for(int i = block_start(b); i <= block_end(b); i++) {
            a[i] += delta[b];
        }
        delta[b] = 0;
        is_lazy[b] = false;
        build(b);
    }
}
long long query_brute(int l, int r) {
    unlazy(block(l));
    long long ans = 0;
    for(int i = l; i <= r; i++) {
        ans += a[i];
    }
    return ans;
}
long long query_smart(int l, int r) {
    long long ans = 0;
    for(int b = l; b <= r; b++) {
        ans += bin[b] + delta[b] * SQRTN;
    }
    return ans;
}
long long query(int l, int r) {
    if(block(l) == block(r)) {
        return query_brute(l, r);
    } else {
        return query_brute(l, block_end(block(l)))
             + query_smart(block(l) + 1, block(r) - 1)
             + query_brute(block_start(block(r)), r);
    }
}
void update_brute(int l, int r, long long v) {
    unlazy(block(l));
    for(int i = l; i <= r; i++) {
        a[i] += v;
    }
    build(block(l));
}
void update_smart(int l, int r, long long v) {
    for(int b = l; b <= r; b++) {
        delta[b] += v;
        is_lazy[b] = true;
    }
}
void update(int l, int r, long long v) {
    if(block(l) == block(r)) {
        update_brute(l, r, v);
    } else {
        update_brute(l, block_end(block(l)), v);
        update_smart(block(l) + 1, block(r) - 1, v);
        update_brute(block_start(block(r)), r, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(bin, 0, sizeof bin);
    memset(delta, 0, sizeof delta);
    memset(is_lazy, false, sizeof is_lazy);
    for(int b = 0; b <= block(n - 1); b++) {
        build(b);
    }
}
