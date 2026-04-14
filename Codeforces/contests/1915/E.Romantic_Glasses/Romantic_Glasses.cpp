#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        int num; cin >> num;
        if(i & 1) v[i] = -num;
        else v[i] = num;
    }
    
    ll cur = 0;
    set<ll> dif;
    dif.insert(0);
    for(int i = n-1; i >= 0; i--)
    {
        cur += v[i];
        if(dif.count(cur))
        {
            cout << "YES\n";
            return;
        }
        dif.insert(cur);
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}
