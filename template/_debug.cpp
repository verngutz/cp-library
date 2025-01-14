#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T> concept NonStringRange = ranges::range<T> and not is_convertible_v<T, string_view>; 
template <NonStringRange T> ostream& operator<<(ostream& os, const T& c) {
    os << "[";
    for(auto it = begin(c); it != end(c); it++) {
        if(it != begin(c)) os << ", ";
        os << *it;
    }
    return os << "]";
}
vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while(getline(ss, x, c)) {
        v.push_back(x);
    }
    return v;
}
#define err(args...) { error(split(#args, ' ').begin(), args); }
void error(vector<string>::iterator it) {
    cerr << "\033[0m" << endl;
}
template <typename T, typename... Args> void error(vector<string>::iterator it, T a, Args... args) {
	cerr << "\033[0;32;1m" << it->substr((*it)[0] == ' ', it->back() == ',' ? it->size() - 1 : it->size()) << " = " << a << "; ";
	error(++it, args...);
}
