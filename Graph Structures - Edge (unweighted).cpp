#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v;
    edge reverse() const { return {v, u}; }
    friend ostream& operator<<(ostream& os, const edge& e) {
        return os << "{u: " << e.u << ", v: " << e.v << "}";
    }
};
