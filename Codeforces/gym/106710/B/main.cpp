#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    int n; cin >> n;
    ll mat[n][n], inc[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
            inc[i][j] = 0;
        }
    }

    int m; cin >> m;
    while(m--) {
        int i, j, x, y, k; cin >> i >> j >> x >> y >> k;
        i--; j--; x--; y--;
        
        inc[min(i, x)][min(j, y)] += k;
        
        if(max(i, x)+1 < n)
            inc[max(i, x)+1][min(j, y)] -= k;

        if(max(j, y)+1 < n)
            inc[min(i, x)][max(j, y)+1] -= k;

        if(max(i, x)+1 < n && max(j, y)+1 < n)
            inc[max(i, x)+1][max(j, y)+1] += k;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                continue;
            } else if(i == 0) {
                inc[i][j] += inc[i][j-1];
            } else if(j == 0) {
                inc[i][j] += inc[i-1][j];
            } else {
                inc[i][j] += inc[i-1][j] + inc[i][j-1] - inc[i-1][j-1];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            } else if(mat[i][j] == -1) {
                continue;
            } else {
                mat[i][j] += inc[i][j];
            }
        }
    }
/*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
*/
    // FW
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][k] != -1 && mat[k][j] != -1) {
                    if(mat[i][k]+mat[k][j] < mat[i][j] || mat[i][j] == -1) {
                        mat[i][j] = mat[i][k]+mat[k][j];
                    }
                }
            }
        }
    }

    // Q
    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << mat[a][b] << "\n";
    }
}