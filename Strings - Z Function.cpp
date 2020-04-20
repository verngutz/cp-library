#include <bits/stdc++.h>
using namespace std;
// z[i] is the length of the longest common prefix between s and the suffix of s starting at i
vector<int> make_z_function(const string& s) {
    vector<int> z(s.length());
    z[0] = s.length();
    for(int i = 1, L = 0, R = 0; i < s.length(); i++) {
        z[i] = i < R ? min(z[i - L], R - i) : 0;
        while(i + z[i] < s.length() and s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if(R < i + z[i]) {
            L = i, R = i + z[i];
        }
    }
    return z;
}
