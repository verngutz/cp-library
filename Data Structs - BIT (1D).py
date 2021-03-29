class bit:
    def __init__(self, n): self.n, self.t = n, [0 for i in range(n + 1)]
    def add(self, i, value): 
        while i <= self.n: self.t[i] += value; i += i & -i
    def sum(self, i, res=0):
        while i > 0: res += self.t[i]; i -= i & -i
        return res
    def rsq(self, L, R): return self.sum(R) - self.sum(L - 1)
