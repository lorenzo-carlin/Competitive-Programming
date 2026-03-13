#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        for(int u: adj[t]) {
            if(!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}
