#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k, n; cin >> k >> n;
    vector<int> v(n);
    for(auto &el: v) cin >> el;

    int mx = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j <= k && i+j < n; ++j)
        {
            mx = max(mx, v[i+j]-v[i]);
        }
    }

    cout << mx << "\n";
}