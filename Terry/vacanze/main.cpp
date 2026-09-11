#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for(int p = 1; p <= t; ++p)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> adj_s(n);
        for(int i = 0; i < m; ++i)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            adj_s[a].insert(b);
            adj_s[b].insert(a);
        }
        ll cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            for(auto x:adj[i])
            {
                for(auto y:adj[x])
                {
                    if(y == i)
                    {
                        continue;
                    }
                    auto l = adj_s[y].find(i);
                    if(l != adj_s[y].end())
                    {
                        continue;
                    }
                    for(auto w:adj[y])
                    {
                        if(w == i || w == x)
                        {
                            continue;
                        }
                        auto m = adj_s[w].find(x);
                        if(m != adj_s[w].end())
                        {
                            continue;
                        }
                        auto n = adj_s[w].find(i);
                        if(n != adj_s[w].end())
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        cout << "Case #" << p << ": " << cnt/8 << endl;
    }
}