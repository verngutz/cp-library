#include <bits/stdc++.h>
using namespace std;
using ll = long long;
seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
const uint64_t M1 = (1ull << 61) - 1;
const uint64_t M2 = (1ull << 31) - 1;
const uint64_t X1 = uniform_int_distribution<uint64_t>(256, M1-1)(rng);
const uint64_t X2 = uniform_int_distribution<uint64_t>(256, M2-1)(rng);
uint64_t modadd(uint64_t a, uint64_t b, uint64_t M) {
    return a + b >= M ? a + b - M : a + b;
}
uint64_t modmul1(uint64_t a, uint64_t b) {
	uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
	uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
	uint64_t ret = (l & M1) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & M1) + (ret >> 61);
	ret = (ret & M1) + (ret >> 61);
	return ret - 1;
}
uint64_t modmul2(uint64_t a, uint64_t b) {
    uint64_t ret = a * b + 1;
    ret = (ret & M2) + (ret >> 31);
    ret = (ret & M2) + (ret >> 31);
    return ret - 1;
}
struct hash_struct {
    uint64_t M;
    vector<uint64_t> prefix, mpow;
    const function<uint64_t(uint64_t, uint64_t)> modmul;
    hash_struct(uint64_t M, int n, const function<uint64_t(uint64_t, uint64_t)>& modmul)
    : M(M), prefix(n), mpow(n), modmul(modmul) {}
};
hash_struct make_prefix_hash1(string& s) {
    hash_struct h(M1, s.size(), modmul1);
    for(int i = 0; i < s.size(); i++) {
        h.prefix[i] = modadd(modmul1(i ? h.prefix[i - 1] : 0, X1), s[i], M1);
        h.mpow[i] = i ? modmul1(h.mpow[i - 1], X1) : 1;
    }
    return h;
}
hash_struct make_prefix_hash2(string& s) {
    hash_struct h(M2, s.size(), modmul2);
    for(int i = 0; i < s.size(); i++) {
        h.prefix[i] = modadd(modmul2(i ? h.prefix[i - 1] : 0, X2), s[i], M2);
        h.mpow[i] = i ? modmul2(h.mpow[i - 1], X2) : 1;
    }
    return h;
}
uint64_t get_substring_hash(hash_struct& h, int L, int R) {
    return R >= L ? modadd(h.prefix[R], (L ? h.M - h.modmul(h.mpow[R - L + 1], h.prefix[L - 1]) : 0), h.M) : 0;
}
