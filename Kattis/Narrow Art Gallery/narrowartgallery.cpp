#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAX = 200;
int mat[MAX][MAX*2];

int solve(int posx, int posy, int rem, vector<pair<int,int>> &v)
{
    // casi base
    if(posy >= n)
        return 1e6;
    if(rem == 1)
    {
        if(posx == 0)
        {
            return min(v[posy].first, solve(posx, posy+1, rem, v));
        } else if(posx == 1)
        {
            return min(v[posy].second, solve(posx, posy+1, rem, v));
        }
    }

    int mn = 1e8;

    // prendo
    // riga successiva
    if(posx == 0)
    {
        mn = min(mn, solve(posx, posy+1, rem-1, v) + v[posy].first);
    } else if(posx == 1)
    {
        mn = min(mn, solve(posx, posy+1, rem-1, v) + v[posy].second);
    }
    // resto delle righe
    for(int i = posy+2; i < n; ++i)
    {
        if(posx == 0)
        {
            mn = min(mn, solve(0, i, rem-1, v) + v[posy].first);
            mn = min(mn, solve(1, i, rem-1, v) + v[posy].first); 
        } else
        {
            mn = min(mn, solve(0, i, rem-1, v) + v[posy].second);
            mn = min(mn, solve(1, i, rem-1, v) + v[posy].second);
        }
        
    }

    // non prendo
    for(int i = posy+1; i < n; ++i)
    {
        mn = min(mn, solve(0, i, rem, v));
        mn = min(mn, solve(1, i, rem, v));
    }

    return mn;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;

    vector<pair<int,int>> v;
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        sum += a; sum += b;
        v.push_back({a,b});
    }

    int a, b; cin >> a >> b;
    int ans = min(solve(0, 0, k, v), solve(1, 0, k, v));

    //cout << ans << endl;

    cout << sum-ans;
}