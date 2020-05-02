#include <bits/stdc++.h>
using namespace std;
template <typename T> struct wedge {
    int u, v; T w;
    wedge reverse() const { return {v, u, w}; }
    friend ostream& operator<<(ostream& os, const wedge& e) {
        return os << "{u: " << e.u << ", v: " << e.v << ", w: " << e.w << "}";
    }
};
