#include <bits/stdc++.h>
using namespace std;
bool subseq(string& s, string& t, int i=0, int j=0) {
    if(j == t.length()) {
        return true;
    } else if(i == s.length()) {
        return false;
    } else if(s[i] == t[j]) {
        return subseq(s, t, i + 1, j + 1);
    } else {
        return subseq(s, t, i + 1, j);
    }
}
