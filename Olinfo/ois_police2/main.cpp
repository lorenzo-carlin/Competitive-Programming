#include <bits/stdc++.h>
using namespace std;

int dfs(int pos, vector<int> &v, vector<bool> &vis, vector<int> &tmp)
{
    int j = 0;
    tmp[pos] = j;
    vis[pos] = true;
    while(true)
    {
        j++;
        pos = v[pos];
        if(vis[pos])
        {
            return j-tmp[pos];
        }
        tmp[pos] = j;
        vis[pos] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    vector<bool> vis(n, false);
    vector<int> tmp(n, 0);
    for(auto &i:v) cin >> i;
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!vis[i])
        {
            mx = max(mx,dfs(i, v, vis, tmp));
        }
    }
    cout << mx << endl;
}