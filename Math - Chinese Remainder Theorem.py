import math

def lcm(a, b):
    return a * b // math.gcd(a, b)

def ex_gcd(a, b):
    if b == 0:
        return 1, 0
    else:
        x, y = ex_gcd(b, a % b)
        return y, x - a // b * y

def crt(a, b, m, n):
    if (a - b) % math.gcd(m, n) == 0:
        u, v = ex_gcd(m, n)
        lamb = (a - b) // math.gcd(m, n)
        return True, (b + n * v * lamb) % lcm(m, n) or lcm(m, n)
    else:
        return False, None
