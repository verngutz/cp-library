#include <bits/stdc++.h>
using namespace std;
// NOTE: zero-indexed
template <typename T>
class sparse_table {
private:
    vector<int> lg;
    vector<vector<T>> st;
public:
    const T zero;
    const function<T(T, T)> combine;
    const int size;
    sparse_table(T zero, const function<T(T, T)>& combine, const vector<T>& a)
    : zero(zero), combine(combine), size(a.size()), lg(size + 1) {
        lg[1] = 0;
        for(int i = 2; i <= size; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        st.resize(lg[size] + 1, vector<T>(size, zero));
        for(int pow2 = 0; pow2 <= lg[size]; pow2++) {
            for(int i = 0; i + (1 << pow2) - 1 < size; i++) {
                st[pow2][i] = pow2 ? combine(st[pow2 - 1][i], st[pow2 - 1][i + (1 << (pow2 - 1))]) : a[i];
            }
        }
    }
    T query(int i, int j) {
        int k = lg[j - i + 1];
        return combine(st[k][i], st[k][j - (1 << k) + 1]);
    }
};