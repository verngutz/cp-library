#include <bits/stdc++.h>
#include "Binary Search the Answer (int).cpp"
using namespace std;
const int N = 100'000;
string s;
int n, sa[N+1], pos[N+1], va[N+1], c[N+1];
bool equal(int i, int j, int gap) {
    return pos[i] == pos[j] && i + gap < n && pos[i + gap / 2] == pos[j + gap / 2];
}
void buildSA() {
    s += '$';
    n = s.length();
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }
    sort(sa, sa + n, [](int i, int j) {
        return pos[i] != pos[j] ? pos[i] < pos[j] : j < i;
    });
    for(int gap = 1; gap < n * 2; gap <<= 1) {
        va[sa[0]] = 0;
        for(int i = 1; i < n; i++) {
            int prev = sa[i - 1], next = sa[i];
            va[next] = equal(prev, next, gap) ? va[prev] : i;
        }
        for(int i = 0; i < n; ++i) {
            pos[i] = va[i];
            va[i] = sa[i];
            c[i] = i;
        }
        for(int i = 0; i < n; i++) {
            int id = va[i] - gap;
            if (id >= 0) {
                sa[c[pos[id]]++] = id;
            }
        }
    }
}
bool sa_match_range(const string& t, int start, int len, int& L, int& R) {
    auto t_start = t.begin() + start;
    auto t_end = t.begin() + start + len;
    L = bsearch(-1, n, [&](int i) {
        if(i == n) {
            return true;
        } else {
            auto s_begin = s.begin() + sa[i];
            auto s_end = s.begin() + min(int(s.length()), sa[i] + len);
            return lexicographical_compare(t_start, t_end, s_begin, s_end)
            or equal(t_start, t_end, s_begin, s_end);
        }
    }, false);
    R = bsearch(0, n, [&](int i) {
        auto s_begin = s.begin() + sa[i];
        auto s_end = s.begin() + min(int(s.length()), sa[i] + len);
        return lexicographical_compare(s_begin, s_end, t_start, t_end)
        or equal(s_begin, s_end, t_start, t_end);
    });
    return L <= R;
}
