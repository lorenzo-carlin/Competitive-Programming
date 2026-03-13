#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int find(int node, vector<int> &father)
{
    if(father[node] != node)
    {
        father[node] = find(father[node], father);
    }
    return father[node];
}

void unite(int a, int b, vector<int> &father)
{
    int rA = find(a, father);
    int rB = find(b, father);
    if(rand() % 2)
    {
        father[rA] = rB;
    } else
    {
        father[rB] = rA;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    vector<pair<int,pair<int,int>>> v;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        v.push_back({-c, {a, b}});
    }

    sort(v.rbegin(), v.rend());
    vector<bool> vis(n, false);
    ll ans = 0;
    for(int i = 0; i < m; ++i)
    {
        int c = -v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if(find(x, father) != find(y, father))
        {
            unite(x, y, father);
            vis[x] = true;
            vis[y] = true;
            ans += c;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        father[i] = find(i, father);
        if(i != 0 && father[i] != father[i-1])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << ans << "\n";
}