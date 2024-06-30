#include <bits/stdc++.h>
#include "Geometry - Vectors.cpp"
#include "Geometry - Lines.cpp"
using namespace std;
template <typename T> struct segment2D {
    vec2D<T> p1, p2;
    T power(const vec2D<T>& p) const { return (p1 - p) | (p2 - p); }
    T turn(const vec2D<T>& p) const { return (p2 - p1) * (p - p1); }
    bool contains(const vec2D<T>& p) const { return power(p) <= 0 and turn(p) == 0; }
    double distance(const vec2D<T>& p) const {
        if(p1 != p2 and (p - p1) | (p2 - p1) >= 0 and (p - p2) | (p1 - p2) >= 0) {
            return abs(turn(p)) / (p2 - p1).norm();
        } else {
            return min((p - p1).norm(), (p - p2).norm());
        }
    }
    bool operator==(const segment2D& s) const {
        return (p1 == s.p1 and p2 == s.p2) or (p1 == s.p2 and p2 == s.p1);
    }
    bool operator!=(const segment2D& s) const { return not (*this == s); }
    bool has_proper_intersection(const segment2D& s) const {
        return (turn(s.p1) > 0 != turn(s.p2) > 0) and (s.turn(p1) > 0 != s.turn(p2) > 0);
    }
    vec2D<T> proper_intersection(const segment2D& s) const {
        return line2D<T>(p1, p2).intersection(line2D<T>(s.p1, s.p2));
    }
    set<vec2D<T>> intersection(const segment2D& s) const {
        if(has_proper_intersection(s)) {
            return {proper_intersection(s)};
        } else {
            set<vec2D<T>> ans;
            for(const vec2D<T>& v : {p1, p2, s.p1, s.p2}) {
                if(contains(v) and s.contains(v)) {
                    ans.insert(v);
                }
            }
            return ans;
        }
    }
    friend ostream& operator<<(ostream& os, const segment2D<T>& s) { return os << s.p1 << "-" << s.p2; }
    friend istream& operator>>(istream& is, segment2D<T>& s) { return is >> s.p1 >> s.p2; }
};
