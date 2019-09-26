#include <bits/stdc++.h>
using namespace std;
using ll = long long;
seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
template <typename T> struct rolling_hash {
    static uint64_t add(uint64_t a, uint64_t b) { return a + b >= T::M ? a + b - T::M : a + b; }
    static uint64_t sub(uint64_t a, uint64_t b) { return T::add(a, T::M - b); }
    static uint64_t mul(uint64_t, uint64_t);
    static inline uint64_t X = uniform_int_distribution<uint64_t>(256, T::M - 1)(rng);
    static inline vector<uint64_t> mpow;
    static void resize(int n) {
        T::mpow.reserve(n + 1);
        while(T::mpow.size() <= n) {
            T::mpow.push_back(T::mpow.empty() ? 1 : T::mul(T::mpow.back(), T::X));
        }
    }
    vector<uint64_t> prefix;
    rolling_hash() {}
    rolling_hash(const string& s) { append(s); }
    uint64_t query(int L, int R) {
        assert(L <= R), assert(R <= prefix.size());
        resize(R - L);
        return L ? T::sub(prefix[R - 1], T::mul(prefix[L - 1], T::mpow[R - L])) : prefix[R - 1];
    }
    T& append(char c) {
        prefix.push_back(prefix.empty() ? c : T::add(T::mul(prefix.back(), T::X), c));
        return (T&)*this;
    }
    T& append(const string& s) {
        prefix.reserve(prefix.size() + s.size());
        for(const char& c : s) {
            push_back(c);
        }
        return (T&)*this;
    }
    T& operator+=(char c) { return append(c); }
    T& operator+=(const string& s) { return append(s); }
    void push_back(char c) { append(c); }
    void pop_back() { prefix.pop_back(); }
};
struct hash1 : public rolling_hash<hash1> {
    static const uint64_t M = (1ull << 61) - 1;
    static uint64_t mul(uint64_t a, uint64_t b) {
        uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
        uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        uint64_t ret = (l & M) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & M) + (ret >> 61);
        ret = (ret & M) + (ret >> 61);
        return ret - 1;
    }
    hash1() {}
    hash1(const string& s) : rolling_hash<hash1>(s) {}
};
struct hash2 : public rolling_hash<hash2> {
    static const uint64_t M = (1ull << 31) - 1;
    static uint64_t mul(uint64_t a, uint64_t b) {
        uint64_t ret = a * b + 1;
        ret = (ret & M) + (ret >> 31);
        ret = (ret & M) + (ret >> 31);
        return ret - 1;
    }
    hash2() {}
    hash2(const string& s) : rolling_hash<hash2>(s) {}
};
