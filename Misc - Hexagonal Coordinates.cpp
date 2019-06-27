#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using hex_coord = tuple<int, int, int>;
int x(const hex_coord& h) { return get<0>(h); }
int y(const hex_coord& h) { return get<1>(h); }
int z(const hex_coord& h) { return get<2>(h); }
int dx[] = { 0, -1, -1,  0, +1, +1};
int dy[] = {+1, +1,  0, -1, -1,  0};
int dz[] = {-1,  0, +1, +1,  0, -1};
int norm(const hex_coord& h) {
    return max({abs(x(h)), abs(y(h)), abs(z(h))});
}
vector<hex_coord> generate_ring(int r) {
    if(r == 0) {
        return {{0, 0, 0}};
    } else {
        vector<hex_coord> ring;
        hex_coord cell = {r, -r, 0};
        for(int d = 0; d < 6; d++) {
            for(int i = 0; i < r; i++) {
                ring.push_back(cell);
                cell = {x(cell) + dx[d], y(cell) + dy[d], z(cell) + dz[d]};
            }
        }
        return ring;
    }
}
vector<hex_coord> generate_grid(int r) {
    vector<hex_coord> grid;
    for(int i = 0; i <= r; i++) {
        vector<hex_coord> ring = generate_ring(i);
        grid.insert(grid.end(), ring.begin(), ring.end());
    }
    return grid;
}
vector<hex_coord> generate_corners(int r) {
    vector<hex_coord> corners;
    for(int d = 0; d < 6; d++) {
        corners.push_back({r * dx[d], r * dy[d], r * dz[d]});
    }
    return corners;
}
pair<double, double> rect_coords_flat_top(const hex_coord& h) {
    return {3.0 / 2 * x(h), sqrt(3) * y(h) + sqrt(3) / 2 * x(h)};
}
pair<double, double> rect_coords_pointy_top(const hex_coord& h) {
    return {sqrt(3) * x(h) + sqrt(3) / 2 * z(h), -3.0 / 2 * z(h)};
}
pair<ll, ll> squared_quadrupled_rect_coords_flat_top(const hex_coord& h) {
    return {9ll * x(h) * x(h), 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h)};
}
pair<ll, ll> squared_quadrupled_rect_coords_pointy_top(const hex_coord& h) {
    return {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h), 9ll * z(h) * z(h)};
}
vector<pair<double, double>> vertices(const pair<double, double>& center, bool flat_top = true) {
    vector<pair<double, double>> ans = {
        {1, 0},
        {-1, 0},
        {1.0 / 2, sqrt(3) / 2},
        {1.0 / 2, -sqrt(3) / 2},
        {-1.0 / 2, sqrt(3) / 2},
        {-1.0 / 2, -sqrt(3) / 2}
    };
    if(not flat_top) {
        for(auto [i, j] : ans) {
            swap(i, j);
        }
    }
    auto [ci, cj] = center;
    for(auto [i, j] : ans) {
        i += ci, j += cj;
    }
    return ans;
}
vector<pair<ll, ll>> squared_quadrupled_vertices_flat_top(const hex_coord& h) {
    return {
        {9ll * x(h) * x(h) + 12 * x(h) + 4, 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h)},
        {9ll * x(h) * x(h) - 12 * x(h) + 4, 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h)},
        {9ll * x(h) * x(h) + 6 * x(h) + 1, 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h) + 6 * x(h) + 12 * y(h) + 3},
        {9ll * x(h) * x(h) + 6 * x(h) + 1, 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h) - 6 * x(h) - 12 * y(h) + 3},
        {9ll * x(h) * x(h) - 6 * x(h) + 1, 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h) + 6 * x(h) + 12 * y(h) + 3},
        {9ll * x(h) * x(h) - 6 * x(h) + 1, 3ll * x(h) * x(h) + 12ll * x(h) * y(h) + 12ll * y(h) * y(h) - 6 * x(h) - 12 * y(h) + 3},
    };
}
vector<pair<ll, ll>> squared_quadrupled_vertices_pointy_top(const hex_coord& h) {
    return {
        {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h), 9ll * z(h) * z(h) - 12 * z(h) + 4},
        {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h), 9ll * z(h) * z(h) + 12 * z(h) + 4},
        {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h) + 12 * x(h) + 6 * z(h) + 3, 9ll * z(h) * z(h) - 6 * z(h) + 1},
        {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h) - 12 * x(h) - 6 * z(h) + 3, 9ll * z(h) * z(h) - 6 * z(h) + 1},
        {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h) + 12 * x(h) + 6 * z(h) + 3, 9ll * z(h) * z(h) + 6 * z(h) + 1},
        {12ll * x(h) * x(h) + 12ll * x(h) * z(h) + 3ll * z(h) * z(h) - 12 * x(h) - 6 * z(h) + 3, 9ll * z(h) * z(h) + 6 * z(h) + 1}
    };
}
ll T(ll n) {
    return n * (n + 1) / 2;
}
ll n_cells_in_grid(int r) {
    return 1 + 6 * T(r);
}
