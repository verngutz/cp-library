#include <bits/stdc++.h>
#define N 100'000
using namespace std;
using ll = long long;
vector<int> adj[N+1];
void link(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int degree[N+1];
int height[N+1];
deque<int> find_centers(int n) {
    deque<int> q;
    for(int u = 1; u <= n; u++) {
        degree[u] = adj[u].size();
        if(degree[u] <= 1) {
            height[u] = 1;
            q.push_back(u);
        }
    }
    for(int i = 0; i < q.size(); i++) {
        int u = q[i];
        for(int v : adj[u]) {
            if(--degree[v] == 1) {
                height[v] = height[u] + 1;
                q.push_back(v);
            }
        }
    }
    while(height[q.front()] < height[q.back()]) {
        q.pop_front();
    }
    return q;
}
int d[N+1];
vector<int> farthest_from(int s, int center, int height_offset) {
    vector<int> ans;
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        if(d[u] + height_offset == height[center]) {
            ans.push_back(u);
        }
        for(int v : adj[u]) {
            if(v != center and d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return ans;
}
int find_diameter(int n, const deque<int>& centers, vector<vector<int>>& diameter_groups) {
    auto by_height = [](int u, int v) { return height[u] > height[v]; };
    if(n == 1) {
        diameter_groups.push_back({centers[0]});
        return 0;
    } else if(n == 2) {
        diameter_groups.push_back({centers[0]});
        diameter_groups.push_back({centers[1]});
        return 1;
    } else if(centers.size() == 1) {
        int c0 = centers[0];
        sort(adj[c0].begin(), adj[c0].end(), by_height);
        fill(d, d + n + 1, -1);
        for(int i = 0; i < adj[c0].size() and height[adj[c0][i]] >= height[adj[c0][1]]; i++) {
            diameter_groups.push_back(farthest_from(adj[c0][i], c0, 1));
        }
        return height[adj[c0][0]] + height[adj[c0][1]];
    } else {
        int c0 = centers[0], c1 = centers[1];
        sort(adj[c0].begin(), adj[c0].end(), by_height);
        sort(adj[c1].begin(), adj[c1].end(), by_height);
        fill(d, d + n + 1, -1);
        diameter_groups.push_back(farthest_from(c0, c1, 0));
        diameter_groups.push_back(farthest_from(c1, c0, 0));
        return height[adj[c0][1]] + height[adj[c1][1]] + 1;
    }
}
ll n_partners[N+1];
ll count_farthest_pairs(int n, vector<vector<int>>& diameter_groups) {
    if(n == 1) {
        return 1;
    } else {
        ll sum = 0;
        for(auto& group : diameter_groups) {
            sum += group.size();
        }
        ll ans = 0;
        for(auto& group : diameter_groups) {
            for(int u : group) {
                n_partners[u] = sum - group.size();
            }
            ans += group.size() * (sum - group.size());
        }
        return ans;
    }
}
