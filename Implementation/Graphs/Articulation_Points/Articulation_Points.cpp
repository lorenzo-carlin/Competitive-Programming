#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
vector<int> articolation_points;
int tmr = 0;

// tin: tempo di entrata nel nodo
// low: minimo tra i tin di ogni discendente di v e i tin di ogni backedge che parte da un discendente di v

void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = tmr++;
	int children = 0;
	for(int u: adj[v]) {
		if(u == p) continue;
		if(visited[u]) {
			low[v] = min(low[v], tin[u]);
		} else {
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if(low[u] >= tin[v] && p != -1) {
				articulation_points.push_back(v);
			}
			children++;
		}
	}
	if(p == -1 && children > 1) {
		articulation_points.push_back(v);
	}
}
