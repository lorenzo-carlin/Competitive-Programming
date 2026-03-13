#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
const int INF = 1e9;
vector<vector<int>> adj(N);
vector<int> dist(N, INF);

vector<int> shortest_path(int v) {
    queue<int> q;
    q.push(v);
    dist[v] = 0;

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        for(int u: adj[t]) {
            if(dist[u] == INF) {
                q.push(u);
                dist[u] = dist[t]+1;
            }
        }
    }

    return dist;
}
