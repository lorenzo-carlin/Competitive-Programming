#include <bits/stdc++.h>
using namespace std;

int n;

int solve(int pos, vector<pair<int,int>> &v, vector<bool> &b)
{
    int x = v[pos].first;
    int y = v[pos].second;

    b[pos] = true;
    
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!b[i])
        {
            if(v[i].first == y)
            {
                mx = max(mx, solve(i, v, b)+1);
            } else if(v[i].second == y)
            {
                swap(v[i].first, v[i].second);
                mx = max(mx, solve(i, v, b)+1);
            }
        }
    }

    b[pos] = false;

    return mx;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<pair<int,int>> v(n);
    vector<bool> b(n, false);
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        mx = max(mx, solve(i, v, b)+1);
        swap(v[i].first, v[i].second);
        mx = max(mx, solve(i, v, b)+1);
        //cout << mx << "\n";
    }
    cout << mx << "\n";
}