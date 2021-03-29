def max_flow(g, s, t):
    d = []
    def make_level_graph():
        nonlocal d
        d = [0 if u == s else -1 for u in len(g.adj)]
        q = [s]
        for u in q:
            for e in g[u]:
                if g(e).resid() > 0 and d[g(e).v] == -1:
                    d[g(e).v] = d[g(e).u] + 1
                    q.append(g(e).v)
        return d[t] != -1
    def augment(u, b):
        if u == t: return b
        for j in range(adj_ptr[u], len(g[u])):
            _, v, c, f = g(g[u][j])
            # if d[v] == d[u] + 1 and c - f > 0 and (df := augment(v, min(b, c - f))):
            while d[v] == d[u] + 1 and c - f > 0:
                df = augment(v, min(b, c - f))
                if not df: break
            ###
                g(g[u][j]).f += df; g(g[u][j] ^ 1).f -= df
                return df
            adj_ptr[u] = j + 1
        return 0
    ans = 0
    while make_level_graph():
        adj_ptr = [0 for _ in len(g.adj)]
        # while df := augment(s, float('inf')):
        while True:
            df = augment(s, float('inf'))
            if not df: break
        ###
            ans += df
    return ans
