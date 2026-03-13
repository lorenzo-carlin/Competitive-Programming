#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t; cin >> n >> t;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    int l = 0, r = 0, curr = 0, mx = 0;
    for(; l < n; l++)
    {
        while(r < n && curr + v[r] <= t)
        {
            curr += v[r];
            r++;
        }
        mx = max(mx, r-l);
        //cout << mx << "\n";
        curr -= v[l];
    }

    cout << mx << "\n";
}