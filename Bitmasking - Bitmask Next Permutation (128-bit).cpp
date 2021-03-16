__int128_t next_permutation(__int128_t mask) {
    __int128_t t = (mask | (mask - 1)) + 1;
    return t | ((((t & -t) / (mask & -mask)) >> 1) - 1);
}