def max_matching(g, L, R):
    matched = [False for _ in range(L + 1)]
    partner = [0 for _ in range(R + 1)]
    d = []
    def make_level_graph():
        nonlocal d
        d = [-1 if matched[u] else 0 for u in range(L + 1)]
        q = [u for u in range(L + 1) if not matched[u]]
        has_unmatched = False
        for u in q:
            for v in g[u]:
                if not partner[v]:
                    has_unmatched = True
                elif d[partner[v]] == -1:
                    d[partner[v]] = d[u] + 1
                    q.append(partner[v])
        return has_unmatched
    def find_alt_path(u):
        for j in range(adj_ptr[u], len(g[u])):
            v = adj_ptr[u][j]
            if not partner[v] or (d[partner[v]] == d[u] + 1 and find_alt_path(partner[v])):
                partner[v] = u
                return True
            adj_ptr[u] = j + 1
        return False
    while make_level_graph():
        adj_ptr = [0 for _ in range(L + 1)]
        for u in range(1, L + 1):
            if not matched[u] and find_alt_path(u):
                matched[u] = True
    return partner
