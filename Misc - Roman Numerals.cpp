#include <bits/stdc++.h>
using namespace std;
string R[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
int H[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
int roman_to_int(string& s) {
    int ans = 0, d = 0;
    for(int i = 0; i < 13; i++) {
        while(s.length() <= R[i].length() and s.substr(d, R[i].length()) == R[i]) {
            ans += H[i];
            d += R[i].length();
        }
    }
    return ans;
}
string int_to_roman(int n) {
    string ans;
    for(int i = 0; i < 13; i++) {
        while(n >= H[i]) {
            ans += R[i];
            n -= H[i];
        }
    }
    return ans;
}
