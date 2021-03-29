def generate_primes(n):
    is_prime = [False if i <= 1 else True for i in range(n + 1)]
    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                is_prime[j] = False
    return primes
