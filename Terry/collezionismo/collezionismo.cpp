#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for(int x = 1; x <= t; ++x)
    {
        int n, k; cin >> n >> k;

        vector<int> v(n);
        for(auto &i: v) cin >> i;
        sort(v.begin(), v.end());

        vector<int> d;
        for(int i = 0; i < n-1; ++i)
        {
            d.push_back(v[i] - v[i+1]);
        }
        sort(d.begin(), d.end());

        int sol = v[n-1] - v[0];
        for(int i = 0; i < k-1; ++i)
        {
            sol += d[i];
        }

        cout << "Case #" << x << ": " << sol << "\n";
    }
}