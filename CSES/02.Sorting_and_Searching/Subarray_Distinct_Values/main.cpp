#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) cin >> i;

    ll ans = 0;

    map<int,int> mp;
    int l = 0, r = 0;
    mp[v[0]]++;
    for(; l < n; l++)
    {
        while(r < n && mp.size() <= k)
        {
            r++;
            mp[v[r]]++;
        }

        if(mp.size() > k || r == n)
        {
            ans += (r - l);
        }

        mp[v[l]]--;
        if(mp[v[l]] == 0)
        {
            mp.erase(v[l]);
        }
    }

    cout << ans << "\n";
}