#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    ll n, m; cin >> n >> m;
    vector<ll> f(n), s(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> f[i] >> s[i];
    }

    map<ll,ll> mp;
    ll mn = 1e18, sum = 0;
    int l = 0, r = 0;
    for(; l < n; l++)
    {
        while(r < n && sum < m)
        {
            mp[s[r]]++;
            sum += f[r];

            if(sum >= m)
            {
                auto it = mp.end();
                it--;
                mn = min(mn, (*it).first);
            }

            r++;
        }

        mp[s[l]]--;
        if(mp[s[l]] == 0)
        {
            mp.erase(s[l]);
        }
        sum -= f[l];
    }

    cout << mn << "\n";

}