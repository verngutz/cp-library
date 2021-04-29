import random
def make_tree(n):
    return ((i, random.randint(1, i - 1)) for i in range(2, n + 1))
