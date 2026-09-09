#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

int m, n, k;
string str;
vector<vector<pair<int,char>>> adj;

void dfs(int node, int ind)
{
    if(ind == k)
    {
        cout << node << "\n";
        return;
    }
    for(auto el: adj[node])
    {
        if(el.s == str[ind])
        {
            dfs(el.f, ind+1);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;

    for(int i = 0; i < k; ++i) cin >> str[i];

    adj.resize(n+1);

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dfs(1, 0);
}