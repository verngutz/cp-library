#include <bits/stdc++.h>
using namespace std;

int set(int x, int b) { return x | 1 << b; }
int unset(int x, int b) { return x & ~(1 << b); }
int flip(int x, int b) { return x ^ 1 << b; }
bool is_set(int x, int b) { return x & 1 << b; }
int log2(int x) { return 31 - __builtin_clz(x); }
int LSB(int x) { return x & -x; }
int LSB2(int x) { return 1 << __builtin_ffs(x) - 1; }

int main() {
    __builtin_ffs; // index of LSB + 1
    __builtin_clz; // number of leading 0 bits
    __builtin_ctz; // number of trailing 0 bits
    __builtin_popcount; // number of 1 bits

    __builtin_ffsll; // index of LSB + 1
    __builtin_clzll; // number of leading 0 bits
    __builtin_ctzll; // number of trailing 0 bits
    __builtin_popcountll; // number of 1 bits

    return 0;
}
