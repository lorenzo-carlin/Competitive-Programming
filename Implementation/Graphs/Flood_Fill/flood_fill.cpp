#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000;
int mat[N][N];
bool vis[N][N];

void flood_fill(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= N || vis[x][y] || mat[x][y] == '#') return;

    vis[x][y] = true;
    flood_fill(x+1, y);
    flood_fill(x, y+1);
    flood_fill(x-1, y);
    flood_fill(x, y-1);
}


const int N = 1000;
int mat[N][N];
bool vis[N][N];
int x_change[4] = {0, 1, 0, -1};
int y_change[4] = {1, 0, -1, 0};

void flood_fill(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= N || vis[x][y] || mat[x][y] == '#') return;

    vis[x][y] = true;
    for(int i = 0; i < 4; ++i) {
        flood_fill(x + x_change[i], y + y_change[i]);
    }
}

