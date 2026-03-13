#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 1e9;

    vector<bool> vis(n, false);
    vis[0] = true;

    queue<pair<int,int>> q;
    q.push({0, 1});

    map<int,int> father;
    father[0] = -1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto el:adj[x])
        {
            if(!vis[el])
            {
                if(el == n-1)
                {
                    ans = y+1;
                }
                q.push({el, y+1});
                father[el] = x;
                vis[el] = true;
            }
        }
    }

    if(ans == 1e9)
    {
        cout << "IMPOSSIBLE\n";
    } else
    {
        cout << ans << "\n";

        stack<int> s;
        int ind = n-1;
        while(ind != -1)
        {
            s.push(ind);
            ind = father[ind];
        }

        while(!s.empty())
        {
            cout << s.top()+1 << " ";
            s.pop();
        }
    }
}