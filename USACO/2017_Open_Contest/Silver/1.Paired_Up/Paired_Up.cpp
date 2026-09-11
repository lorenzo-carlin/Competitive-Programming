#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    int l = 0, r = n-1, mx = 0;
    while(l <= r)
    {
        int s = min(v[l].second, v[r].second);
        if(l == r) s /= 2;
        mx = max(mx, v[l].first + v[r].first);
        v[l].second -= s;
        v[r].second -= s;
        if(v[l].second == 0) l++;
        if(v[r].second == 0) r--;
    }

    cout << mx << "\n";
}