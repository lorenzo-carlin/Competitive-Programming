#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    while(n--)
    {
        ll a, b; cin >> a >> b;
        ll mn = min(a, b), mx = max(a, b);
        ll ris;
        if(mn == a)
        {
            if(mx % 2)
            {
                ll tmp = mx*mx;
                ris = tmp - mn + 1;
            } else
            {
                ll tmp = (mx-1)*(mx-1)+1;
                ris = tmp + mn - 1;
            }
        } else
        {
            if(mx % 2)
            {
                ll tmp = (mx-1)*(mx-1)+1;
                ris = tmp + mn - 1;
            } else
            {
                ll tmp = mx*mx;
                ris = tmp - mn + 1;
            }
        }
        cout << ris << "\n";
    }
}