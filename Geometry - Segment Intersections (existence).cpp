#include <bits/stdc++.h>
#include "Geometry - Segments.cpp"
using namespace std;
template <typename T> struct event {
    enum struct type_t { open, close };
    type_t type;
    T x, y;
    int i;
    bool operator<(const event& e) const {
        return tuple(x, y, type) < tuple(e.x, e.y, e.type);
    }
};
template <typename T> bool has_intersections(const vector<segment2D<T>>& segments) {
    vector<vec2D<T>> opening(segments.size()), closing(segments.size());
    vector<event<T>> events;
    for(int i = 0; i < segments.size(); i++) {
        opening[i] = min(segments[i].p1, segments[i].p2);
        closing[i] = max(segments[i].p1, segments[i].p2);
        events.push_back({event<T>::type_t::open, opening[i].x, opening[i].y, i});
        events.push_back({event<T>::type_t::close, closing[i].x, closing[i].y, i});
    }
    sort(events.begin(), events.end());
    auto cmp = [&](int i, int j) { 
        return pair(opening[i].y, i) < pair(opening[j].y, j); 
    };
    set<int, decltype(cmp)> s(cmp);
    for(const event<T>& e : events) {
        if(e.type == event<T>::type_t::open) {
            s.insert(e.i);
        } else {
            auto it = s.find(e.i);
            if(++it != s.end() and segments[e.i].intersection(segments[*it]).size() > 0) {
                return true;
            }
            if(--it != s.begin() and segments[e.i].intersection(segments[*--it]).size() > 0) {
                return true;
            }
            s.erase(e.i);
        }
    }
    return false;
}