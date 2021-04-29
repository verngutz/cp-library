import random
def make_complete_graph(n, m):
        edges = []
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                edges.append(random.choice([(i, j), (j, i)]))
        return edges
