def bsearch(L, R, can, left_feasible = True):
    while R - L > 1:
        M = L + (R - L) // 2
        if can(M) ^ left_feasible:
            R = M
        else:
            L = M
    return L if left_feasible else R