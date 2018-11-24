#include <bits/stdc++.h>
#define N 100'000
using namespace std;

vector<int> adj[N+1];

void generate_random_tree(int size) {
    for(int u = 2; u <= size; u++) {
        int v = rand() % (u-1) + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
