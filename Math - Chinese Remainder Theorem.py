from functools import reduce
from math import gcd
from operator import mul


def lcm(a, b):
    return a * b // gcd(a, b)


def ex_gcd(a, b):
    if b == 0:
        return 1, 0
    else:
        x, y = ex_gcd(b, a % b)
        return y, x - a // b * y


def crt(system):
    N = reduce(mul, (ni for ni, _ in system))
    ans = 0
    for ni, ai in system:
        Ni = N // ni
        Mi, _ = ex_gcd(Ni, ni)
        ans += ai * Mi * Ni
    return ans
