#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    char mat[n][4];
    for(int i = 0; i < n; ++i)
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2] >> mat[i][3];
    for(int i = n-1; i >= 0; i--)
    {
        if(mat[i][0] == '#') cout << 1 << " ";
        if(mat[i][1] == '#') cout << 2 << " ";
        if(mat[i][2] == '#') cout << 3 << " ";
        if(mat[i][3] == '#') cout << 4 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
