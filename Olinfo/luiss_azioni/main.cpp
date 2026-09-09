#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    int mx = 0;
    for(int i = 0; i < n-1; ++i)
    {
        mx = max(mx, abs(v[i]-v[i+1]));
    }
    cout << mx << "\n";
}