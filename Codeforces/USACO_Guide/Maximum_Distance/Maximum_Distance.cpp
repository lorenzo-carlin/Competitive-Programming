#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].first;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].second;
    }
    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int dist = (v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
            mx = max(mx, dist);
        }
    }
    cout << mx << "\n";
}