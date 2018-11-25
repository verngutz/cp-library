#include <bits/stdc++.h>
using namespace std;
bool subseq(const string& s, const string& t, int i = 0, int j = 0) {
    for(int i = 0, j = 0; i < s.length() and j < t.length(); i++) {
        j += s[i] == t[j];
    }
    return j == t.length();
}
