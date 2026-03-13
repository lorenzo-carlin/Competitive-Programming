#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    ll sum = 0;
    for(ll i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    ll av = (sum+n-1) / n;
    if(av == k)
    {
        cout << 0 << "\n";
        return 0;
    }
    if(av < k)
    {
        cout << 1 << "\n";
        return 0;
    }
    sort(v.rbegin(), v.rend());
    ll tmp = sum, ind = 0;
    while(ind < n)
    {
        tmp -= (v[ind]-1);
        if((tmp+n-1)/n <= k)
        {
            ind++;
            break;
        }
        ind++;
    }
    cout << ind << "\n";
}