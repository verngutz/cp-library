#include "Data Structs - BIT (1D).cpp"
struct binary_trie {
    const int word_size;
    bit<int> b;
    binary_trie(int size) : word_size(__lg(size - 1) + 1), b(1 << word_size) {}
    int get(int ptr, int i, bool x) {
        return ptr | (x << i);
    }
    int count(int ptr, int i) {
        return b.sum(ptr + 1, ptr + (1 << i));
    }
    int min_xor(int x = 0) {
        if(b.sum(1 << word_size) == 0) {
            return x;
        } else {
            int ans = 0;
            for(int i = word_size - 1, ptr = 0; i >= 0; i--) {
                if(count(get(ptr, i, x & (1 << i)), i)) {
                    ptr = get(ptr, i, x & (1 << i));
                } else {
                    ptr = get(ptr, i, not (x & (1 << i)));
                    ans |= 1 << i;
                }
            }
            return ans;
        }
    }
    int max_xor(int x = 0) { return ~min_xor(~x); }
    int mex(int x = 0) {
        int ans = 0;
        for(int i = word_size - 1, ptr = 0, c; i >= 0 and (c = count(get(ptr, i, x & (1 << i)), i)); i--) {
            if(c < 1 << i) {
                ptr = get(ptr, i, x & (1 << i));
            } else {
                ptr = get(ptr, i, not (x & (1 << i)));
                ans |= 1 << i;
            }
        }
        return ans;
    }
};