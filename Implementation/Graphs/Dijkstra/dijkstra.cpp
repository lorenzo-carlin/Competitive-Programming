#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000;
vector<vector<pair<int,int>>> adj(N);
vector<int> dist(N, INF);

vector<int> dijkstra(int s) {
    priority_queue<pair<int,int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()) {
        int d = -pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(dist[v] < d) continue;

        for(auto [u, q] : adj[v]) {
            if(dist[v]+q < dist[u]) {
                dist[u] = dist[v]+q;
                pq.push({-dist[u], u});
            }
        }
    }

    return dist;
}

