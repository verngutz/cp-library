class segtree:
    def __init__(self, size, monoid):
        self.size, self.monoid, self.tree = size, monoid, [monoid.identity for i in range(2 * (size + 1))]
    def update(self, i, x):
        i += self.size; self.tree[i] = x; i >>= 1
        while i: self.tree[i] = self.monoid.combine(self.tree[i << 1], self.tree[(i << 1) | 1]); i >>= 1
    def query(self, a, b, inclusive=True):
        ans_l, ans_r = self.monoid.identity, self.monoid.identity
        a += self.size; b += self.size + inclusive
        while a < b:
            if a & 1: ans_l = self.monoid.combine(ans_l, self.tree[a]); a += 1
            if b & 1: b -= 1; ans_r = self.monoid.combine(self.tree[b], ans_r)
            a >>= 1; b >>= 1
        return self.monoid.combine(ans_l, ans_r)
    def point_query(self, i): return self.query(i, i)
