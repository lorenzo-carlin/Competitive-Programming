#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;
    int MAX = 1005;
    vector<vector<int>> ps(MAX, vector<int> (MAX, 0));

    for(int i = 0; i < MAX; ++i)
    {
        ps[i][0] = 0;
        ps[0][i] = 0;
    }

    for(int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        ps[x1][y1]++; ps[x2][y2]++;
        ps[x1][y2]--; ps[x2][y1]--;
    }
    
    int sol = 0;
    for(int i = 1; i < MAX; ++i)
    {
        for(int j = 1; j < MAX; ++j)
        {
            ps[i][j] += (ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1]);
            if(ps[i][j] == k) sol++;
        }
    }
    
    cout << sol << "\n";
}