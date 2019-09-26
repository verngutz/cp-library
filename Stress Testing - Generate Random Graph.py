from random import randint
def make_graph(n, m, multigraph=False, edges=None):
    edges = edges or set()
    if not multigraph:
        assert m <= n * (n - 1) // 2 - len(edges)
    for i in range(m):
        while True:
            u, v = randint(1, n), randint(1, n)
            if multigraph or frozenset((u, v)) not in edges:
                break
        yield (u, v)
        edges.add(frozenset((u, v)))
