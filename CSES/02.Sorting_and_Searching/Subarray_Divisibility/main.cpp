#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;

    vector<ll> ps; ps.push_back(0);
    map<int,int> mp; mp[0]++;
    ll sol = 0;
    for(int i = 0; i < n; ++i)
    {
        ll a; cin >> a;
        ll tmp = (ps.back()+a >= 0) ? ((ps.back()+a)%n) : ((ps.back()+a+n*1000000000)%n);
        ps.push_back(tmp);
        sol += mp[tmp];
        mp[tmp]++;
    }

    cout << sol << "\n";
}