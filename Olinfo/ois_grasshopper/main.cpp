#include <bits/stdc++.h>
using namespace std;

enum
{
    nonvisitato,
    sorvolato,
    atterrato,
    ok
};

int main()
{
    // input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> st(n, nonvisitato);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    st[0] = atterrato;

    // bfs
    queue<pair<int,int>> q;
    q.push({0, atterrato});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(y != st[x])
        {
            continue;
        }
        for(auto el:adj[x])
        {
            int k = st[el];
            if(y == ok)
            {
                st[el] = ok;
            } else if(y == sorvolato)
            {
                if(st[el] == nonvisitato)
                {
                    st[el] = atterrato;
                } else if(st[el] == sorvolato)
                {
                    st[el] = ok;
                }
            } else if(y == atterrato)
            {
                if(st[el] == nonvisitato)
                {
                    st[el] = sorvolato;
                } else if(st[el] == atterrato)
                {
                    st[el] = ok;
                }
            }
            if(k != st[el])
            {
                q.push({el, st[el]});
            }
        }
    }

    int ans = 0;
    for(auto el: st)
    {
        if(el == ok || el == atterrato)
        {
            ans++;
        }
    }

    cout << ans << "\n";
}