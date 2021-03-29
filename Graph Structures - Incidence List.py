class graph:
    def __init__(self, n, oneway, index=1):
        self.oneway, self.index, self.adj, self.edges = oneway, index, [[] for i in range(n + index)], []
    def __len__(self): return len(self.adj) - self.index
    def __getitem__(self, u): return self.adj[u]
    def __call__(self, e): return self.edges[e]
    def __repr__(self): return repr(self.edges)
    def append(self, u, edge): self.adj[u].append(len(self.edges)); self.edges.append(edge)
    def add_edge(self, edge):
        self.append(edge.u, edge)
        if not self.oneway: self.append(edge.v, reversed(edge))
