def sssp(g, s):
    import heapq
    done = [False for _ in range(len(g.adj))]
    p = [-1 for _ in range(len(g.adj))]
    d = [float('inf') for _ in range(len(g.adj))]
    for u in s: d[u] = 0
    pq = [(d[u], u) for u in s]
    while len(pq) > 0:
        _, u = heapq.heappop(pq)
        if not done[u]:
            done[u] = True
            for e in g[u]:
                if d[g(e).v] > d[g(e).u] + g(e).w:
                    d[g(e).v] = d[g(e).u] + g(e).w; p[g(e).v] = e
                    heapq.heappush((d[g(e).v], g(e).v))
    return d, p
