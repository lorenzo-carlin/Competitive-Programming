#include <bits/stdc++.h>
using namespace std;

bool palindromic(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    if(a == s)
    {
        return true;
    } else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int p = 1; p <= t; ++p)
    {
        //input
        int n, m; cin >> n >> m;
        int st, fn; cin >> st >> fn;
        vector<vector<pair<int,char>>> adj(n);
        for(int i = 0; i < m; ++i)
        {
            int a, b; cin >> a >> b;
            char c; cin >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        //risoluzione
        queue<pair<int,string>> q;
        q.push({st, ""});
        while(!q.empty())
        {
            int x = q.front().first;
            string y = q.front().second;
            //cout << y.size() << endl;
            q.pop();

            if(x == fn && palindromic(y))
            {
                cout << "Case #" << p << ": " << y.size() << endl;
                break;
            }

            if(q.size() > 1e8)
            {
                cout << "Case #" << p << ": -1" << endl;
                break;
            }

            for(auto [i,j]:adj[x])
            {
                q.push({i, y+j});
            }
        }
    }
}