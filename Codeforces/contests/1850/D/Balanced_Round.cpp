#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;

        vector<int> v(n);
        for(auto &i: v) cin >> i;
        sort(v.begin(), v.end());

        int mx = 1, cur = 1;
        for(int i = 0; i < n-1; ++i)
        {
            if(v[i+1] - v[i] <= k) cur++;
            else cur=1;
            if(cur > mx) mx = cur;
        }

        cout << n-mx << "\n";
    }
}