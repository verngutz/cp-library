using ll = long long;
constexpr auto ctz(int x) { return __builtin_ctz(x);      } constexpr auto ctz(ll x) { return __builtin_ctzll(x);      }
constexpr auto clz(int x) { return __builtin_clz(x);      } constexpr auto clz(ll x) { return __builtin_clzll(x);      }
constexpr auto pop(int x) { return __builtin_popcount(x); } constexpr auto pop(ll x) { return __builtin_popcountll(x); }
