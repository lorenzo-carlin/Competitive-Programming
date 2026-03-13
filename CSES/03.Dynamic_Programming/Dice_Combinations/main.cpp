#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9+7;

int main()
{
    int n; cin >> n;
    vector<ll> v(n+1,0);
    v[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        ll t = 0;
        for(int j = i-1; j >= 0 && i-6 <= j; j--)
        {
            t += v[j];
        }
        v[i] = t%mod;
    }
    cout << v[n];
}