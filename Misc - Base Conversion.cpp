#include <bits/stdc++.h>
using namespace std;
template <typename T> string int_to_string(T n, int radix = 10) {
    if(n == 0) {
        return "0";
    } else {
        string ans;
        while(n > 0) {
            ans += n % radix <= 9 ? n % radix + '0' : n % radix - 10 + 'A';
            n /= radix;
        }
        while(ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}
template <typename T> T string_to_int(const string& s, int radix = 10) {
    T ans = 0, pow = 1;
    for(int i = s.length() - 1; i >= 0; i--) {
        ans += ('0' <= s[i] and s[i] <= '9' ? s[i] - '0' : 10 + s[i] - 'A') * pow;
        pow *= radix;
    }
    return ans;
}
