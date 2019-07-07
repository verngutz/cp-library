constexpr int lg(int x) { return x ? 31 - __builtin_clz(x) : 0; }
