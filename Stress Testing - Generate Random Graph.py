from random import randint

def make_graph(n, m):
    return ((randint(1, n), randint(1, n)) for i in range(m))
