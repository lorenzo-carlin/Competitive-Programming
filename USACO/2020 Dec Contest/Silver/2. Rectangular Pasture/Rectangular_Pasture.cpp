#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ycomp(pair<int,int> p1, pair<int,int> p2) {return p1.second < p2.second;}

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i)
    {
        v[i].first = i+1;
    }

    sort(v.begin(), v.end(), ycomp);
    for(int i = 0; i < n; ++i)
    {
        v[i].second = i+1;
    }
    
    sort(v.begin(), v.end());

    vector<vector<int>> ps(n+1, vector<int> (n+1, 0));
    for(int i = 0; i < n; ++i)
    {
        ps[v[i].first][v[i].second] = 1;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int tmp = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            ps[i][j] += tmp;
        }
    }

    ll tot = 0;
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            int mx_x = max(v[i].first, v[j].first);
            int mx_y = max(v[i].second, v[j].second);
            int mn_x = min(v[i].first, v[j].first);
            int mn_y = min(v[i].second, v[j].second);
            ll h = ps[mx_x][n] - ps[mx_x][mx_y] - ps[mn_x-1][n] + ps[mn_x-1][mx_y-1];
            ll l = ps[mx_x][mn_y-1] - ps[mn_x-1][mn_y-1];
            tot += (h+1)*(l+1);
        }
    }

    tot += (n+1);

    cout << tot << "\n";

}