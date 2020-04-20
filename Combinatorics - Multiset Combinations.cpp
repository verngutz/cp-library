#include "Combinatorics - Integer Compositions.cpp"
template <typename T = mint> T multi_C(int n, int k) {
    return C_nonnegative<T>(k, n);
}
