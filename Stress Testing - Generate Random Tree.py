from random import randint
def make_tree(n):
    return ((i, randint(1, i - 1)) for i in range(2, n + 1))
