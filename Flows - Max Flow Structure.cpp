#include <bits/stdc++.h>
#include "Graph Structures - Incidence List.cpp"
using namespace std;
template <typename T> struct fedge {
    int u, v; T c, f;
    T resid() { return c - f; }
    fedge reverse() const { return {v, u, 0, 0}; }
    friend ostream& operator<<(ostream& os, const fedge& e) {
        return os << "{u: " << e.u << ", v: " << e.v << ", c: " << e.c << ", f: " << e.f << "}";
    }
};
template <typename T, bool Index> using flow_graph = graph<0, fedge<T>, Index>;
