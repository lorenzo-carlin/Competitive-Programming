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
    father[rB] = rA;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    vector<pair<ll,pair<int,int>>> v;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b; a--; b--;
        ll c; cin >> c;
        v.push_back({c,{a,b}});
    }
    sort(v.begin(), v.end());

    ll tot = 0;
    vector<pair<int,int>> sol;
    for(int i = 0; i < m; ++i)
    {
        ll w = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(find(a, father) != find(b, father))
        {
            unite(a, b, father);
            tot += w;
            sol.push_back({a, b});
        }
    }

    cout << tot << "\n";
    for(auto el: sol)
    {
        cout << el.first+1 << " " << el.second+1 << "\n";
    }
}