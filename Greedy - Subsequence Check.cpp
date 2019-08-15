#include <bits/stdc++.h>
using namespace std;
bool subseq(const string& s, const string& t, int i = 0, int j = 0) {
    for(; i < s.length() and j < t.length(); j++) {
        i += s[i] == t[j];
    }
    return i == s.length();
}
