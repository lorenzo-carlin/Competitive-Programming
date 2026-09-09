#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;

int MAX = 100;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);    

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(m);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<pair<int,int>>> v(MAX);
    int ind = 0;
    v[ind].push_back({0,-1});

    bool cond = false;
    while(!cond)
    {
        vector<bool> vis(30, false);
        ind++;
        for(auto i:v[ind-1])
        {
            int x = i.first;
            for(auto j:adj[x])
            {
                if(!vis[j])
                {
                    v[ind].push_back({j,x});
                    vis[j] = true;
                }
                if(ind%2 != 0 && j == 0)
                {
                    cond = true;
                    break;
                }
            }
            if(cond)
            {
                break;
            }
        }
    }

    cout << ind << endl;
    int p = 0;
    while(ind > 0)
    {
        for(auto i:v[ind])
        {
            if(i.first == p)
            {
                cout << i.first << " ";
                p = i.second;
                break;
            }
        }
        ind--;
    }
    cout << "0";
}