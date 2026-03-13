#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void dfs(int v);
void bfs(int v);

int conn_comp() {
    int comp = 0;
    for(int i = 0; i < N; ++i) {
        if(!visited[i]) {
            dfs(i);     // o bfs(i);
            comp++;
        }
    }
    return comp;
}
