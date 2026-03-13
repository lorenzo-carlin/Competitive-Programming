#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll n;
 
ll f(ll num)
{
    ll sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        sol += min(n, num/i);
    }
    return sol;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
 
    ll l = 1, r = n*n;
    ll target = (n*n+1)/2;
    while(l < r)
    {
        ll mid = (l + r) / 2;
        if(f(mid) >= target)
        {
            r = mid;
        } else
        {
            l = mid+1;
        }
    }
    cout << r << "\n";
}
