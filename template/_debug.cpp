#include <bits/stdc++.h>
using namespace std;
ostream& print(ostream& os, auto L, auto R) {
    os << "[";
    for(auto it = L; it != R; it++) {
        if(it != L) os << ", ";
        os << *it;
    }
    os << "]";
    return os;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template<typename T>
struct is_container {
private:
    template<typename C> static char test_it(typename C::const_iterator*);
    template<typename C> static long test_it(...);
    template<typename C> static char test_st(typename enable_if<is_same<C, string>::value>::type*);
    template<typename C> static long test_st(...);
    template<typename C> static char test_be(typename enable_if<
        is_same<decltype(static_cast<typename C::const_iterator(C::*)() const>(&C::begin)),
                typename C::const_iterator(C::*)() const>::value>::type*);
    template<typename C> static long test_be(...);
    template<typename C> static char test_en(typename enable_if<
        is_same<decltype(static_cast<typename C::const_iterator(C::*)() const>(&C::end)),
                typename C::const_iterator(C::*)() const>::value>::type*);
    template<typename C> static long test_en(...);
public:
    enum { value = sizeof(test_it<T>(0)) == sizeof(char)
                && sizeof(test_st<T>(0)) == sizeof(long)
                && sizeof(test_be<T>(0)) == sizeof(char)
                && sizeof(test_en<T>(0)) == sizeof(char) };
};
template<typename T>
typename enable_if<is_container<T>::value, ostream&>::type
operator<<(ostream& os, const T& c) {
    return print(os, c.begin(), c.end());
}
template<typename T>
typename enable_if<!is_same<typename remove_cv<T>::type, char>::value, ostream&>::type
operator<<(ostream& os, const T arr[]) {
    return print(os, begin(arr), end(arr));
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
    cerr << endl;
}
template<typename T, typename... Args>
void error(vector<string>::iterator it, T a, Args... args) {
	cerr << it->substr((*it)[0] == ' ', it->back() == ',' ? it->size() - 1 : it->size()) << " = " << a << "; ";
	error(++it, args...);
}
