from sys import maxsize

def bfs(g, q):
    d = [maxsize for _ in range(len(g.adj))]
    p = [-1 for _ in range(len(g.adj))]
    for u in q: d[u] = 0
    for u in q:
        for e in g[u]:
            if d[g(e).v] > d[u] + 1:
                d[g(e).v] = d[u] + 1; p[g(e).v] = e
                q.append(g(e).v)
    return d, p
