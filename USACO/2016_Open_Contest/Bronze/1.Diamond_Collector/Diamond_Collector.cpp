#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        int curr = 0;
        for(int j = i; j < n; ++j)
        {
            if(v[j]-v[i] <= k) curr++;
        } mx = max(mx, curr);
    }

    cout << mx << "\n";
}