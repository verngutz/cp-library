#include "Binary Search the Answer (int).cpp"
#include "Data Structs - BIT (1D).cpp"
template <typename T>
int kth_elem(bit<T>& b, int n, int k) {
    return bsearch(0, n, [&](int i) { return b.sum(i) >= k; }, false);
}
