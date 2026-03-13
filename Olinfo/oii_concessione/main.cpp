#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ps1, ps2;
vector<vector<int>> cnt1, cnt2; 
vector<vector<char>> layer1;

void init(int N, vector<string> M) {
    n = N;
    cnt1.assign(N, vector<int>(N));
    cnt2.assign(N, vector<int>(N));

    // conta lunghezze delle diagonali
    vector<int> len1(2*N-1, 0), len2(2*N-1, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            len1[j - i + N - 1]++;
            len2[i + j]++;
        }
    }

    // alloca ps1 e ps2 (già con dimensione giusta)
    ps1.resize(2*N-1);
    ps2.resize(2*N-1);
    for(int d = 0; d < 2*N-1; d++) {
        ps1[d].assign(len1[d] + 1, 0);
        ps2[d].assign(len2[d] + 1, 0);
    }

    // riempimento ps1
    vector<int> pos1(2*N-1, 1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int d = j - i + N - 1;
            cnt1[i][j] = pos1[d];
            ps1[d][pos1[d]] = ps1[d][pos1[d]-1] + (M[i][j] == '1');
            pos1[d]++;
        }
    }

    // riempimento ps2
    vector<int> pos2(2*N-1, 1);
    for(int i = 0; i < N; i++) {
        for(int j = N-1; j >= 0; j--) {
            int d = i + j;
            cnt2[i][j] = pos2[d];
            ps2[d][pos2[d]] = ps2[d][pos2[d]-1] + (M[i][j] == '1');
            pos2[d]++;
        }
    }

    // riempimento layer1
    if (N > 1) {
        layer1.assign(N-1, vector<char>(N-1, 0));
        for(int i = 0; i < N-1; i++) {
            for(int j = 0; j < N-1; j++) {
                bool a = (M[i][j] == '1');
                bool b = (M[i][j+1] == '1');
                bool c = (M[i+1][j] == '1');
                bool d = (M[i+1][j+1] == '1');
                if((a && d && !b && !c) || (b && c && !a && !d))
                    layer1[i][j] = 1;
            }
        }
    }
}

bool query(int h, int x, int y) {
    if(h == 1) return layer1[x][y];

    int a1 = ps1[y-x+n-1][cnt1[x+h][y+h]]-ps1[y-x+n-1][cnt1[x][y]-1];
    int a2 = ps1[y-x+n-2][cnt1[x+h][y+h-1]]-ps1[y-x+n-2][cnt1[x+1][y]-1];
    int a3 = ps1[y-x+n-3][cnt1[x+h][y+h-2]]-ps1[y-x+n-3][cnt1[x+2][y]-1];
    int a4 = ps1[y-x+n][cnt1[x+h-1][y+h]]-ps1[y-x+n][cnt1[x][y+1]-1];
    int a5 = ps1[y-x+n+1][cnt1[x+h-2][y+h]]-ps1[y-x+n+1][cnt1[x][y+2]-1];

    int b1 = ps2[x+y+h][cnt2[x+h][y]]-ps2[x+y+h][cnt2[x][y+h]-1];
    int b2 = ps2[x+y+h-1][cnt2[x+h-1][y]]-ps2[x+y+h-1][cnt2[x][y+h-1]-1];
    int b3 = ps2[x+y+h-2][cnt2[x+h-2][y]]-ps2[x+y+h-2][cnt2[x][y+h-2]-1];
    int b4 = ps2[x+y+h+1][cnt2[x+h][y+1]]-ps2[x+y+h+1][cnt2[x+1][y+h]-1];
    int b5 = ps2[x+y+h+2][cnt2[x+h][y+2]]-ps2[x+y+h+2][cnt2[x+2][y+h]-1];

    if(a1 == h+1 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0) return true;
    if(b1 == h+1 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0) return true;
    if(a1 == 0 && a2 == h && a3 == h-1 && a4 == h && a5 == h-1) return true;
    if(b1 == 0 && b2 == h && b3 == h-1 && b4 == h && b5 == h-1) return true;
    return false;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<string> M(N);
    for (int i = 0; i < N; i++)
        cin >> M[i];
    
    init(N, M);

    for (int i = 0; i < Q; i++) {
        int h, x, y;
        cin >> h >> x >> y;
        cout << query(h, x, y) << '\n';
    }
}

#endif
