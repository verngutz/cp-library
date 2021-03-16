#include "Bitmasking.cpp"
template <typename T> T next_permutation(T mask) {
    T t = mask | (mask - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (ctz(mask) + 1));
}
