#include <bits/stdc++.h>
using namespace std;

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
    father[rA] = rB;
}

int dist(pair<int,int> a, pair<int,int> b)
{
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n; cin >> n;

    vector<int> father(n);
    for(int i = 0; i < n; ++i)
    {
        father[i] = i;
    }

    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }

    vector<pair<int,pair<int,int>>> d;
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            d.push_back({dist(v[i], v[j]), {i, j}});
        }
    }

    sort(d.begin(), d.end());
    int mx = 0;
    for(int i = 0; i < d.size(); ++i)
    {
        int a = d[i].first;
        int b = d[i].second.first;
        int c = d[i].second.second;
        if(find(b, father) != find(c, father))
        {
            unite(b, c, father);
            mx = max(mx, a);
        }
    }

    cout << mx << "\n";
}