#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;

        vector<ll> v(n);
        for(auto &i: v) cin >> i;

        bool cond = true;
        int l = 0, r = n-1;
        ll sol = 0;
        while(l <= r)
        {
            if(cond && v[l] >= 0) l++;
            else if(!cond && v[l] <= 0) l++;
            else if(cond && v[r] >= 0) r--;
            else if(!cond && v[r] <= 0) r--;
            else
            {
                cond = !cond;
                sol++;
            }
        }

        ll sum = 0;
        for(auto el: v) sum += abs(el);

        cout << sum << " " << sol << "\n";
    }
}