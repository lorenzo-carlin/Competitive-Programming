#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<ll> ps(n+1);
        ps[0] = 0;
        bool cond = false;
        ll curr = 0, sum = 0, mn = 0, mn_ind = -1;
        for(int i = 1; i <= n; ++i)
        {
            ll a; cin >> a;
            ps[i] = ps[i-1] + a;

            if(a > 0)
            {
                cond = false;
                sum = 0;
            } else
            {
                if(!cond)
                {
                    cond = true;
                    curr = i;
                }
                sum += a;
                if(sum < mn)
                {
                    mn = sum;
                    mn_ind = curr;
                }
            }
        }
        if(mn_ind == -1)
        {
            cout << ps.back() << "\n";
        } else
        {
            cout << ps[mn_ind-1] << "\n";
        }
    }
}
