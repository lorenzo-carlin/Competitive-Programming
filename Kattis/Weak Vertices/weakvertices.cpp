#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    while(n != -1)
    {
        //input
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int a; cin >> a;
                if(a == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        //visita
        vector<bool> vis(n, false);
        for(int i = 0; i < n; ++i)
        {
            bool cond = false;
            if(!vis[i])
            {
                if(cond)
                {
                    break;
                }
                for(int x:adj[i])
                {
                    if(cond)
                    {
                        break;
                    }
                    for(int y:adj[x])
                    {
                        if(cond)
                        {
                            break;
                        }
                        for(int w:adj[y])
                        {
                            if(w == i)
                            {
                                vis[i] = true;
                                vis[x] = true;
                                vis[y] = true;
                                cond = true;
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;

        cin >> n;
    }
}