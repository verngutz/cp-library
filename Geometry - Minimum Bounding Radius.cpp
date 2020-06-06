#include <bits/stdc++.h>
#include "Geometry - Lines.cpp"
using namespace std;
template <typename T> using lim = numeric_limits<T>;
template <typename T = double> T minimum_bounding_radius(const vector<vec2D<T>>& p) {
    auto check = [&](const vec2D<T>& center, T radius) {
        return all_of(p.begin(), p.end(), [&](const vec2D<T>& point) {
            return (point - center).norm() <= radius;
        });
    };
    T ans = lim<T>::infinity();
    for(int i = 0; i < p.size(); i++) {
        for(int j = i + 1; j < p.size(); j++) {
            if(check((p[i] + p[j]) / 2, (p[j] - p[i]).norm() / 2)) {
                ans = min(ans, (p[j] - p[i]).norm() / 2);
            }
            for(int k = j + 1; k < p.size(); k++) {
                line2D<T> IJ = {p[i], p[j]}, JK = {p[j], p[k]};
                if(IJ != JK) {
                    auto center = IJ.perp((p[i] + p[j]) / 2).intersection(JK.perp((p[j] + p[k]) / 2));
                    if(check(center, (center - p[i]).norm())) {
                        ans = min(ans, (center - p[i]).norm());
                    }
                }
            }
        }
    }
    return ans;
}