#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void dfs(int v) {
    visited[v] = true;
    for(int u: adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}
