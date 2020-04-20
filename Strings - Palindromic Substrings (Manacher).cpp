#include <bits/stdc++.h>
#define N 100'000
using namespace std;
using ll = long long;
int n, cn;
string s;
int par[N*2+1], child[N*2+1][26];
int lps[N*2+1], node[N*2+1], cs[N*2+1], size;
int currlen[N*2+1];
ll cnt[N*2+1]; // count can be very large
int newNode(int p = -1) {
    cnt[size] = 0; par[size] = p;
    lps[size] = (p == -1 ? 0 : lps[p] + 2);
    memset(child[size], -1, sizeof child[size]);
    return size++;
}
int get(int i, char c) {
    if(child[i][c-'a'] == -1) {
        child[i][c-'a'] = newNode(i);
    }
    return child[i][c-'a'];
}
void manachers() {
    cn = n * 2 + 1;
    for(int i = 0; i < n; i++) {
        cs[i * 2] = -1;
        cs[i * 2 + 1] = s[i];
    }
    size = n * 2;
    int odd = newNode(), even = newNode();
    int cen = 0, rad = 0, L = 0, R = 0;
    size = 0; lps[odd] = -1;
    for(int i = 0; i < cn; i++) {
        node[i] = i % 2 == 0 ? even : get(odd, cs[i]);
    }
    for(int i = 1; i < cn; i++) {
        if(i > rad) {
            L = i - 1;
            R = i + 1;
        } else {
            int M = cen * 2 - i; // retrieve from mirror
            node[i] = node[M];
            if(lps[node[M]] < rad - i) {
                L = -1;
            } else {
                R = rad + 1;
                L = i * 2 - R;
                while(lps[node[i]] > rad - i) {
                    node[i] = par[node[i]];
                }
            }
        }
        // expand palindrome
        while(L >= 0 && R < cn && cs[L] == cs[R]) {
            if(cs[L] != -1) {
                node[i] = get(node[i], cs[L]);
            }
            L--, R++;
        }
        cnt[node[i]]++;
        if(i + lps[node[i]] > rad) {
            rad = i + lps[node[i]];
            cen = i;
        }
    }
    for(int i = size - 1; i >= 0; --i) {
        cnt[par[i]] += cnt[i]; // update parent count
    }
}
