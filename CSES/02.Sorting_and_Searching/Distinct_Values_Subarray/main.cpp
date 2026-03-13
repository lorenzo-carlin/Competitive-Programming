#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    int l = 0, r = 0;
    map<int,int> mp;
    mp[v[0]]++;
    ll ans = 0;
    for(; l < n; l++)
    {
        while(r+1 < n && mp[v[r+1]] < 1)
        {
            r++;
            mp[v[r]]++;
        }

        ans += (r-l+1);

        mp[v[l]]--;
    }

    cout << ans << "\n";
}
