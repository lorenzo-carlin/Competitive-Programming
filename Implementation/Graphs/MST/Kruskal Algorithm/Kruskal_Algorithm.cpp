#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> r;

void make_set(int x)
{
    p.resize(x);
    r.resize(x, 0);
    for(int i = 0; i < x; ++i) p[i] = i;
}

int find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}

void unite(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if(rx != ry)
    {
        if(r[rx] < r[ry])
        {
            p[rx] = ry;
        } else
        {
            p[ry] = rx;
            if(r[rx] == r[ry]) r[rx]++;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    make_set(n);

    vector<pair<int,pair<int,int>>> v;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({-c, {a, b}});
    }

    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        int c = -v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if(find(x) != find(y))
        {
            unite(x, y);
            ans += c;
        }
    }

    cout << ans << "\n";
}